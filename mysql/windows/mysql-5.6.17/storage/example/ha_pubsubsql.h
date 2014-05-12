#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

static ulong pubsubsql_queue_size_mb;

static MYSQL_SYSVAR_ULONG
(	queue_size_mb, pubsubsql_queue_size_mb, 0
,	"Queue size (MB) in the PubSubSQL engine tables"
,	NULL, NULL, 1024, 0, 0, 0
);

static struct st_mysql_sys_var* pubsubsql_sys_var[] =
{	MYSQL_SYSVAR(queue_size_mb)
,	NULL
};

struct st_mysql_storage_engine pubsubsql_storage_engine =
{	MYSQL_HANDLERTON_INTERFACE_VERSION
};

class PubsubsqlHandler : public handler {

public: // factory

	virtual ~PubsubsqlHandler();
	PubsubsqlHandler(handlerton* hton, TABLE_SHARE* table);

public: // iface

	virtual int rnd_next(uchar *buf);
	virtual int rnd_pos(uchar * buf, uchar *pos);
	virtual void position(const uchar *record);
	virtual int info(uint);
	virtual const char * table_type() const;
	virtual const char ** bas_ext() const;
	virtual ulong index_flags(uint idx, uint part, bool all_parts) const;
	virtual THR_LOCK_DATA ** store_lock(THD *thd, THR_LOCK_DATA **to, enum thr_lock_type lock_type);
	virtual int open(const char *name, int mode, uint test_if_locked);
	virtual int close(void);
	virtual int rnd_init(bool scan);
	virtual Table_flags table_flags(void) const;
	virtual int create(const char *name, TABLE *form, HA_CREATE_INFO *info);

};

static handler* pubsubsql_create_handler(handlerton* hton, TABLE_SHARE* table, MEM_ROOT* mem_root) {
	return new (mem_root)PubsubsqlHandler(hton, table);
}

static int pubsubsql_init(void* p) {
	handlerton* pubsubsql_hton = (handlerton *)p;
	pubsubsql_hton->create = pubsubsql_create_handler;
	return 0;
}

mysql_declare_plugin(pubsubsql)
{	MYSQL_STORAGE_ENGINE_PLUGIN
	, &pubsubsql_storage_engine
	, "PUBSUBSQL"
	, "Mykhailo Oksenenko (mike@completedb.com)"
	, "PubSubSQL storage engine"
	, PLUGIN_LICENSE_GPL
	, pubsubsql_init
	, NULL
	, 0x0001
	, NULL
	, pubsubsql_sys_var
	, NULL
}
mysql_declare_plugin_end;
