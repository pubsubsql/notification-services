#include "ha_pubsubsql.h"

PubsubsqlHandler::~PubsubsqlHandler() {
	// void
}

PubsubsqlHandler::PubsubsqlHandler(handlerton* hton, TABLE_SHARE* table)
: handler(hton, table)
{
	// void
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

const char * PubsubsqlHandler::table_type() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

const char ** PubsubsqlHandler::bas_ext() const
{
	throw std::logic_error("The method or operation is not implemented.");
}

ulong PubsubsqlHandler::index_flags(uint idx, uint part, bool all_parts) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

THR_LOCK_DATA ** PubsubsqlHandler::store_lock(THD *thd, THR_LOCK_DATA **to, enum thr_lock_type lock_type)
{
	throw std::logic_error("The method or operation is not implemented.");
}

int PubsubsqlHandler::open(const char *name, int mode, uint test_if_locked)
{
	throw std::logic_error("The method or operation is not implemented.");
}

int PubsubsqlHandler::close(void)
{
	throw std::logic_error("The method or operation is not implemented.");
}

int PubsubsqlHandler::rnd_init(bool scan)
{
	throw std::logic_error("The method or operation is not implemented.");
}

PubsubsqlHandler::Table_flags PubsubsqlHandler::table_flags(void) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

int PubsubsqlHandler::create(const char *name, TABLE *form, HA_CREATE_INFO *info)
{
	throw std::logic_error("The method or operation is not implemented.");
}
