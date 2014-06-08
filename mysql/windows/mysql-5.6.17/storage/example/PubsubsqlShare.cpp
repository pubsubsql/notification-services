#include "PubsubsqlShare.hpp"
#include "PubsubsqlHandler.hpp"
#include "ha_pubsubsql.h"

ulong PubsubsqlShare::getRowCount() const {
	return mRowCount;
}

int PubsubsqlShare::insertRow(uchar* aBuffer) {
	mysql_mutex_lock(&mMutex);
	mRowCount++;
	mysql_mutex_unlock(&mMutex);
	return 0;
}

int PubsubsqlShare::deleteRow(const uchar* aBuffer) {
	mysql_mutex_lock(&mMutex);
	if (mRowCount > 0) {
		mRowCount--;
	}
	mysql_mutex_unlock(&mMutex);
	return 0;
}

//============================================================================

mysql_mutex_t gPubsubsqlMutex;
static HASH gPubsubsqlOpenTables;

//============================================================================
#ifdef HAVE_PSI_INTERFACE
//----------------------------------------------------------------------------

static PSI_mutex_key gKeyMutexPubsubsql;
static PSI_mutex_key gKeyMutexPubsubsqlShare;

static PSI_mutex_info gAllPubsubsqlMutexes[] =
{
	{ &gKeyMutexPubsubsql, "pubsubsql", PSI_FLAG_GLOBAL },
	{ &gKeyMutexPubsubsqlShare, "PubsubsqlShare::mutex", 0 }
};

static void gPubsubsqlInitPsiKeys(void) {
	const char* category = "pubsubsql";
	int count = array_elements(gAllPubsubsqlMutexes);
	mysql_mutex_register(category, gAllPubsubsqlMutexes, count);
}

//----------------------------------------------------------------------------
#endif /* HAVE_PSI_INTERFACE */
//============================================================================
// Stuff for hash BEGIN
//----------------------------------------------------------------------------

static uchar* gPubsubsqlGetKey
(	PubsubsqlShare* aShare
,	size_t* aLength
,	my_bool not_used __attribute__((unused))
) {
	*aLength = aShare->mTableNameLength;
	return (uchar*)aShare->mTableName;
}

//----------------------------------------------------------------------------
// Stuff for hash END
//============================================================================

PubsubsqlShare* PubsubsqlShare::findOrCreateShare
(	const char* aTableName
,	TABLE* aTable
) {
	DBUG_ENTER("PubsubsqlShare::findOrCreateShare");
	//
	PubsubsqlShare* share = nullptr;
	uint length = (uint)strlen(aTableName);
	char* tmpName = nullptr;
	mysql_mutex_lock(&gPubsubsqlMutex);
	//
	// If share is not present in the hash,
	// create a new share and initialize its members.
	share = (PubsubsqlShare*) my_hash_search
	(	&gPubsubsqlOpenTables
	,	(uchar*)aTableName
	,	length
	);
	if (!share) {
		if (!my_multi_malloc(MYF(MY_WME | MY_ZEROFILL),
			&share, sizeof(*share),
			&tmpName, length + 1,
			NullS)
		) {
			mysql_mutex_unlock(&gPubsubsqlMutex);
			DBUG_RETURN(NULL);
		}
		//
		share->mUseCount = 0;
		share->mTableNameLength = length;
		share->mTableName = tmpName;
		strmov(share->mTableName, aTableName);
		share->mRowCount = 0;
		//
		if (my_hash_insert(&gPubsubsqlOpenTables, (uchar*)share)) {
			mysql_mutex_unlock(&gPubsubsqlMutex);
			my_free(share);
			DBUG_RETURN(NULL);
		}
		//
		thr_lock_init(&share->mLock);
		mysql_mutex_init
		(	gKeyMutexPubsubsqlShare
		,	&share->mMutex
		,	MY_MUTEX_INIT_FAST
		);
	}
	//
	share->mUseCount++;
	mysql_mutex_unlock(&gPubsubsqlMutex);
	//
	DBUG_RETURN(share);
}

// Free lock controls.
int PubsubsqlShare::deleteShare(PubsubsqlShare* aShare) {
	DBUG_ENTER("PubsubsqlShare::deleteShare");
	//
	mysql_mutex_lock(&gPubsubsqlMutex);
	int resultCode = 0;
	if (!--aShare->mUseCount) {
		my_hash_delete(&gPubsubsqlOpenTables, (uchar*)aShare);
		thr_lock_delete(&aShare->mLock);
		mysql_mutex_destroy(&aShare->mMutex);
		my_free(aShare);
	}
	mysql_mutex_unlock(&gPubsubsqlMutex);
	//
	DBUG_RETURN(resultCode);
}

void PubsubsqlShare::onInit(void* aHandlertonPointer) {
	//
#ifdef HAVE_PSI_INTERFACE
	gPubsubsqlInitPsiKeys();
#endif
	//
	mysql_mutex_init
	(	gKeyMutexPubsubsql
	,	&gPubsubsqlMutex
	,	MY_MUTEX_INIT_FAST
	);
	//
	(void)my_hash_init
	(	&gPubsubsqlOpenTables
	,	system_charset_info
	,	32, 0, 0
	,	(my_hash_get_key) gPubsubsqlGetKey
	,	0, 0
	);
}

void PubsubsqlShare::onDeinit(void* aHandlertonPointer) {
	my_hash_free(&gPubsubsqlOpenTables);
	mysql_mutex_destroy(&gPubsubsqlMutex);
}

PubsubsqlShare::~PubsubsqlShare() {
	DBUG_ENTER("PubsubsqlShare::~PubsubsqlShare");
	DBUG_VOID_RETURN;
}

PubsubsqlShare::PubsubsqlShare() {
	DBUG_ENTER("PubsubsqlShare::PubsubsqlShare");
	DBUG_VOID_RETURN;
}
