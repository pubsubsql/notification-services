#include "PubsubsqlHandler.hpp"

PubsubsqlHandler::~PubsubsqlHandler() {
	DBUG_ENTER("PubsubsqlHandler::~PubsubsqlHandler");
	DBUG_VOID_RETURN;
}

PubsubsqlHandler::PubsubsqlHandler(handlerton* hton, TABLE_SHARE* table)
: handler(hton, table)
{
	DBUG_ENTER("PubsubsqlHandler::PubsubsqlHandler");
	DBUG_VOID_RETURN;
}

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
	PubsubsqlHandler::Table_flags flags = (HA_NO_TRANSACTIONS | HA_STATS_RECORDS_IS_EXACT | HA_REC_NOT_IN_SEQ);
	DBUG_RETURN(flags);
}

ulong PubsubsqlHandler::index_flags(uint idx, uint part, bool all_parts) const {
	DBUG_ENTER("PubsubsqlHandler::index_flags");
	ulong flags = 0;
	DBUG_RETURN(flags);
}

int PubsubsqlHandler::create(const char* aName, TABLE* aForm, HA_CREATE_INFO* aInfo) {
	DBUG_ENTER("PubsubsqlHandler::create");
	int rcode = 0;
	DBUG_RETURN(rcode);
}

int PubsubsqlHandler::open(const char* aName, int aMode, uint aTestIfLocked) {
	DBUG_ENTER("PubsubsqlHandler::open");

	if (!(mShare = PubsubsqlShare::findOrCreateShare(aName, table)))
		DBUG_RETURN(HA_ERR_OUT_OF_MEM);

	int rcode = 0;
	DBUG_RETURN(rcode);
}

int PubsubsqlHandler::close() {
	DBUG_ENTER("PubsubsqlHandler::close");
	int rcode = 0;
	DBUG_RETURN(rcode);
}






int PubsubsqlHandler::rnd_next(uchar *buf)
{
	throw std::logic_error("The method or operation is not implemented.");
}

int PubsubsqlHandler::rnd_pos(uchar * buf, uchar *pos)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void PubsubsqlHandler::position(const uchar *record)
{
	throw std::logic_error("The method or operation is not implemented.");
}

int PubsubsqlHandler::info(uint)
{
	throw std::logic_error("The method or operation is not implemented.");
}

THR_LOCK_DATA ** PubsubsqlHandler::store_lock(THD *thd, THR_LOCK_DATA **to, enum thr_lock_type lock_type)
{
	throw std::logic_error("The method or operation is not implemented.");
}

int PubsubsqlHandler::rnd_init(bool scan)
{
	throw std::logic_error("The method or operation is not implemented.");
}
