#include "PubsubsqlHandler.hpp"
#include "ha_pubsubsql.h"
#include "table.h"
#include "field.h"

//============================================================================
// Three functions below are needed to enable
// concurrent insert functionality for PUBSUBSQL engine.
// For more details see mysys/thr_lock.c
//----------------------------------------------------------------------------

void gPubsubsqlGetStatus(void* aHandlerPointer, int aConcurrentInsert) {
	PubsubsqlHandler* pubsubsqlHandler =
		(PubsubsqlHandler*) aHandlerPointer;
	//
	pubsubsqlHandler->getStatus();
}

void gPubsubsqlUpdateStatus(void* aHandlerPointer) {
	PubsubsqlHandler* pubsubsqlHandler =
		(PubsubsqlHandler*)aHandlerPointer;
	//
	pubsubsqlHandler->updateStatus();
}

my_bool gPubsubsqlCheckStatus(void* aHandlerPointer) {
	PubsubsqlHandler* pubsubsqlHandler =
		(PubsubsqlHandler*)aHandlerPointer;
	//
	return pubsubsqlHandler->checkStatus();
}

//============================================================================

void PubsubsqlHandler::getStatus() {
	DBUG_ENTER("PubsubsqlHandler::getStatus");
	DBUG_VOID_RETURN;
}

void PubsubsqlHandler::updateStatus() {
	DBUG_ENTER("PubsubsqlHandler::updateStatus");
	DBUG_VOID_RETURN;
}

// This should exist and return 0 for concurrent insert to work.
my_bool PubsubsqlHandler::checkStatus() {
	DBUG_ENTER("PubsubsqlHandler::checkStatus");
	my_bool rcode = 0;
	DBUG_RETURN(rcode);
}

//============================================================================

const char* PubsubsqlHandler::table_type() const {
	DBUG_ENTER("PubsubsqlHandler::table_type");
	const char* str = "PUBSUBSQL";
	DBUG_RETURN(str);
}

const char** PubsubsqlHandler::bas_ext() const {
	DBUG_ENTER("PubsubsqlHandler::bas_ext");
	static const char* exts[] = { 0 };
	DBUG_RETURN(exts);
}

PubsubsqlHandler::Table_flags PubsubsqlHandler::table_flags() const {
	DBUG_ENTER("PubsubsqlHandler::table_flags");
	PubsubsqlHandler::Table_flags flags =
	(	HA_NO_TRANSACTIONS
	|	HA_STATS_RECORDS_IS_EXACT
	|	HA_REC_NOT_IN_SEQ
	|	HA_NO_BLOBS
	);
	DBUG_RETURN(flags);
}

ulong PubsubsqlHandler::index_flags(uint idx, uint part, bool all_parts) const {
	DBUG_ENTER("PubsubsqlHandler::index_flags");
	ulong flags = 0;
	DBUG_RETURN(flags);
}

//============================================================================

int PubsubsqlHandler::create
(	const char* aName
,	TABLE* aForm
,	HA_CREATE_INFO* aInfo
) {
	DBUG_ENTER("PubsubsqlHandler::create");
	int rcode = 0;
	DBUG_RETURN(rcode);
}

int PubsubsqlHandler::open
(	const char* aName
,	int aMode
,	uint aTestIfLocked
) {
	DBUG_ENTER("PubsubsqlHandler::open");
	//
	if (!(mShare = PubsubsqlShare::findOrCreateShare(aName, table))) {
		DBUG_RETURN(HA_ERR_OUT_OF_MEM);
	}
	//
	// Init locking. Pass handler object to the locking routines,
	// so that they could save/update local_saved_data_file_length value
	// during locking. This is needed to enable concurrent inserts.
	thr_lock_data_init(&mShare->mLock, &mLock, (void*) this);
	ref_length = sizeof(my_off_t);
	//
	mShare->mLock.get_status = gPubsubsqlGetStatus;
	mShare->mLock.update_status = gPubsubsqlUpdateStatus;
	mShare->mLock.check_status = gPubsubsqlCheckStatus;
	//
	int rcode = 0;
	DBUG_RETURN(rcode);
}

// We remove ourselves from the shared structure.
// If it is empty we destroy it.
int PubsubsqlHandler::close() {
	DBUG_ENTER("PubsubsqlHandler::close");
	int rcode = PubsubsqlShare::deleteShare(mShare);
	DBUG_RETURN(rcode);
}

//============================================================================

THR_LOCK_DATA ** PubsubsqlHandler::store_lock
(	THD* aThd
,	THR_LOCK_DATA** aTo
,	enum thr_lock_type aLockType
) {
	if (aLockType != TL_IGNORE && mLock.type == TL_UNLOCK) {
		mLock.type = aLockType;
	}
	//
	*aTo++ = &mLock;
	return aTo;
}

//============================================================================

int PubsubsqlHandler::rnd_init(bool aScan) {
	mReturnedData = 0;
	return 0;
}

int PubsubsqlHandler::rnd_next(uchar* aBuffer) {
	if (mReturnedData >= mShare->getRowCount()) {
		setReturnedDataMax();
		return HA_ERR_END_OF_FILE;
	}
	//
	fillRecord(table, aBuffer, ++mReturnedData);
	return 0;
}

void PubsubsqlHandler::position(const uchar* aRecord) {
	*(ulong*)ref = mReturnedData;
}

int PubsubsqlHandler::rnd_pos(uchar* aBuffer, uchar* aPosition) {
	ulong rowNum = 0;
	memcpy(&rowNum, aPosition, sizeof(rowNum));
	fillRecord(table, aBuffer, rowNum);
	return 0;
}

int PubsubsqlHandler::info(uint aFlag) {
	if (aFlag & HA_STATUS_VARIABLE) {
		stats.records = DEFAULT_STATS_RECORDS;
	}
	return 0;
}

//============================================================================

int PubsubsqlHandler::write_row(uchar* aBuffer) {
	//setReturnedDataMax();
	return mShare->insertRow(aBuffer);
}

int PubsubsqlHandler::delete_row(const uchar* aBuffer) {
	setReturnedDataMax();
	return mShare->deleteRow(aBuffer);
}

//============================================================================

void PubsubsqlHandler::setReturnedDataMax() {
	mReturnedData = 0;
	mReturnedData--;
}

void PubsubsqlHandler::fillRecord
(	TABLE* aTable
,	unsigned char* aBuffer
,	ulong aRowNum
) {
	my_bitmap_map* oldMap = tmp_use_all_columns(aTable, aTable->write_set);
	for (uint i = 0; i < aTable->s->fields; i++) {
		Field* field = aTable->field[i];
		my_ptrdiff_t offset = (my_ptrdiff_t) (aBuffer - aTable->record[0]);
		if (field->type() == MYSQL_TYPE_VARCHAR) {
			field->move_field_offset(offset);
			field->set_notnull();
			const char* strData = "Hello PubSubSQL!";
			uint strDataSize = (uint) strlen(strData);
			field->store(strData, strDataSize, system_charset_info);
			field->move_field_offset(-offset);
			break; // fill only first varchar column
		}
	}
	tmp_restore_column_map(aTable->write_set, oldMap);
}

//============================================================================

PubsubsqlHandler::~PubsubsqlHandler() {
	DBUG_ENTER("PubsubsqlHandler::~PubsubsqlHandler");
	DBUG_VOID_RETURN;
}

PubsubsqlHandler::PubsubsqlHandler
(	handlerton* aPubsubsqlHandlerton
,	TABLE_SHARE* aTableShare
)
:	handler(aPubsubsqlHandlerton, aTableShare)
,	DEFAULT_STATS_RECORDS(10)
{
	DBUG_ENTER("PubsubsqlHandler::PubsubsqlHandler");
	DBUG_VOID_RETURN;
}