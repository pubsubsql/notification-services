#include "PubsubsqlHandler.hpp"
#include "ha_pubsubsql.h"
#include "table.h"
#include "field.h"

#include <algorithm>
#include <string>

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
	mCurrentRow = mShare->mRows.peek();
	return 0;
}

int PubsubsqlHandler::rnd_next(uchar* aBuffer) {
	if (mCurrentRow) {
		selectRecord(table, aBuffer);
		mCurrentRow = mCurrentRow->getNext();
		return 0;
	}
	else {
		return HA_ERR_END_OF_FILE;
	}
}

void PubsubsqlHandler::position(const uchar* aRecord) {
	*(ulong*)ref = 0;
}

int PubsubsqlHandler::rnd_pos(uchar* aBuffer, uchar* aPosition) {
	selectRecord(table, aBuffer);
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
	mCurrentRow.reset();
	return insertRecord(table, aBuffer);
}

int PubsubsqlHandler::update_row(const uchar* aOldData, uchar* aNewData) {
	mCurrentRow.reset();
	return updateRecord(table, aNewData);
}

int PubsubsqlHandler::delete_row(const uchar* aBuffer) {
	mCurrentRow.reset();
	return deleteRecord(table, aBuffer);
}

//============================================================================

void PubsubsqlHandler::selectRecord(TABLE* aTable, uchar* aBuffer) {
	my_ptrdiff_t offset = (my_ptrdiff_t)(aBuffer - aTable->record[0]);
	my_bitmap_map* oldMap = dbug_tmp_use_all_columns(aTable, aTable->write_set);
	for (uint i = 0; i < aTable->s->fields; i++) {
		Field* field = aTable->field[i];
		if (field->type() == MYSQL_TYPE_VARCHAR) {
			field->move_field_offset(offset);
			field->set_notnull();
			//
			const char* str = "";
			uint strLen = 0;
			if (mCurrentRow) {
				str = mCurrentRow->c_str();
				strLen = (uint)mCurrentRow->c_str_len();
			}
			//
			field->store(str, strLen, system_charset_info);
			field->move_field_offset(-offset);
			break; // select first varchar column only
		}
	}
	dbug_tmp_restore_column_map(aTable->write_set, oldMap);
}

//----------------------------------------------------------------------------

int PubsubsqlHandler::insertRecord(TABLE* aTable, uchar* aBuffer) {
	char tmpBuffer[1024];
	String tmpString(tmpBuffer, sizeof(tmpBuffer), system_charset_info);
	//
	my_ptrdiff_t offset = (my_ptrdiff_t)(aBuffer - aTable->record[0]);
	my_bitmap_map* oldMap = dbug_tmp_use_all_columns(aTable, aTable->read_set);
	for (uint i = 0; i < aTable->s->fields; i++) {
		Field* field = aTable->field[i];
		if (field->type() == MYSQL_TYPE_VARCHAR) {
			if (field->is_null()) {
				mShare->insertRow(nullptr);
			}
			else {
				field->move_field_offset(offset);
				String* sqlString = field->val_str(&tmpString, &tmpString);
				const char* str = sqlString->c_ptr();
				mShare->insertRow(str);
				field->move_field_offset(-offset);
			}
			break; // read first varchar column only
		}
	}
	dbug_tmp_restore_column_map(aTable->read_set, oldMap);
	//
	return 0;
}

//----------------------------------------------------------------------------

int PubsubsqlHandler::updateRecord(TABLE* aTable, uchar* aBuffer) {
	char tmpBuffer[1024];
	String tmpString(tmpBuffer, sizeof(tmpBuffer), system_charset_info);
	//
	my_ptrdiff_t offset = (my_ptrdiff_t)(aBuffer - aTable->record[0]);
	my_bitmap_map* oldMap = dbug_tmp_use_all_columns(aTable, aTable->read_set);
	for (uint i = 0; i < aTable->s->fields; i++) {
		Field* field = aTable->field[i];
		if (field->type() == MYSQL_TYPE_VARCHAR) {
			if (field->is_null()) {
				updateRecordDefault();
			}
			else {
				field->move_field_offset(offset);
				String* sqlString = field->val_str(&tmpString , &tmpString);
				const char* str = sqlString->c_ptr();
				if (str) {
					updateRecordCommand(str);
				}
				else {
					updateRecordDefault();
				}
				field->move_field_offset(-offset);
			}
			break; // read first varchar column only
		}
	}
	dbug_tmp_restore_column_map(aTable->read_set, oldMap);
	//
	return 0;
}

//----------------------------------------------------------------------------

int PubsubsqlHandler::deleteRecord(TABLE* aTable, const uchar* aBuffer) {
	return mShare->deleteRow(aBuffer);
}

//============================================================================

void PubsubsqlHandler::updateRecordDefault() {
	// void
}

void PubsubsqlHandler::updateRecordCommand(const char* aCommand) {
	std::string cmd = aCommand;
	std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
	if (0 == cmd.find(COMMAND_CONNECT)) {
		updateRecordConnect(aCommand);
	}
	else if (0 == cmd.find(COMMAND_DISCONNECT)) {
		updateRecordDisconnect();
	}
	else {
		updateRecordDefault();
	}
}

//----------------------------------------------------------------------------

void PubsubsqlHandler::updateRecordConnect(const char* aCommand) {
	// void
}

void PubsubsqlHandler::updateRecordDisconnect() {
	// void
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
,	COMMAND_CONNECT("CONNECT")
,	COMMAND_DISCONNECT("DISCONNECT")
{
	DBUG_ENTER("PubsubsqlHandler::PubsubsqlHandler");
	DBUG_VOID_RETURN;
}
