#include "PubsubsqlShare.hpp"

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

static void initPubsubsqlPsiKeys(void) {
	const char* category = "pubsubsql";
	int count = array_elements(gAllPubsubsqlMutexes);
	mysql_mutex_register(category, gAllPubsubsqlMutexes, count);
}

//----------------------------------------------------------------------------
#endif /* HAVE_PSI_INTERFACE */
//============================================================================
// Stuff for hash BEGIN
//----------------------------------------------------------------------------

static uchar* pubsubsqlGetKey
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

PubsubsqlShare* PubsubsqlShare::findOrCreateShare(const char* aTableName, TABLE* aTable) {
	DBUG_ENTER("PubsubsqlShare::getShare");
	//
	PubsubsqlShare* share = nullptr;
	uint length = (uint)strlen(aTableName);
	char* tmpName = nullptr;
	mysql_mutex_lock(&gPubsubsqlMutex);
	//
	// If share is not present in the hash, create a new share and initialize its members.
	share = (PubsubsqlShare*)my_hash_search(&gPubsubsqlOpenTables, (uchar*)aTableName, length);
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
		share->mTableName = tmpName;
		strmov(share->mTableName, aTableName);
		share->mTableNameLength = length;
		share->mUseCount = 0;
		//
		if (my_hash_insert(&gPubsubsqlOpenTables, (uchar*)share)) {
			mysql_mutex_unlock(&gPubsubsqlMutex);
			my_free(share);
			DBUG_RETURN(NULL);
		}
		//
		thr_lock_init(&share->mLock);
		mysql_mutex_init(gKeyMutexPubsubsqlShare, &share->mMutex, MY_MUTEX_INIT_FAST);
	}
	//
	share->mUseCount++;
	mysql_mutex_unlock(&gPubsubsqlMutex);
	//
	DBUG_RETURN(share);
}

void PubsubsqlShare::onInit() {
	mysql_mutex_init(gKeyMutexPubsubsql, &gPubsubsqlMutex, MY_MUTEX_INIT_FAST);
	(void)my_hash_init(&gPubsubsqlOpenTables, system_charset_info, 32, 0, 0,
		(my_hash_get_key)pubsubsqlGetKey, 0, 0);
}

void PubsubsqlShare::onDeinit() {
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
