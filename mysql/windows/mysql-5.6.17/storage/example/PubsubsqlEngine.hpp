#ifndef PUBSUBSQL_ENGINE_HPP
#define PUBSUBSQL_ENGINE_HPP

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

class PubsubsqlHandler : public handler {

public: // factory

	virtual ~PubsubsqlHandler();
	PubsubsqlHandler(handlerton* hton, TABLE_SHARE* table);

public: // iface

	virtual const char* table_type() const;
	virtual const char** bas_ext() const;
	virtual Table_flags table_flags() const;
	virtual ulong index_flags(uint idx, uint part, bool all_parts) const;

	virtual int create(const char* name, TABLE* form, HA_CREATE_INFO* info);
	virtual int open(const char* name, int mode, uint test_if_locked);
	virtual int close();

	virtual int rnd_next(uchar *buf);
	virtual int rnd_pos(uchar * buf, uchar *pos);
	virtual void position(const uchar *record);
	virtual int info(uint);
	virtual THR_LOCK_DATA ** store_lock(THD *thd, THR_LOCK_DATA **to, enum thr_lock_type lock_type);
	virtual int rnd_init(bool scan);

};

#endif /* PUBSUBSQL_ENGINE_HPP */
