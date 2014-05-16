#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

#include "PubsubsqlEngine.hpp"

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

static handler* pubsubsql_create_handler(handlerton* hton, TABLE_SHARE* table, MEM_ROOT* mem_root);
static int pubsubsql_init(void* p);

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
