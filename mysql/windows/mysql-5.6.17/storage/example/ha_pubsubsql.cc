#include "ha_pubsubsql.h"

//============================================================================
// Stuff for system variables BEGIN
//----------------------------------------------------------------------------

static ulong pubsubsql_queue_size_mb;

static MYSQL_SYSVAR_ULONG
(	queue_size_mb, pubsubsql_queue_size_mb, 0
,	"Queue size (MB) in the PubSubSQL engine tables"
,	NULL, NULL, 1024, 0, 0, 0
);

static struct st_mysql_sys_var* pubsubsql_sys_vars[] =
{	MYSQL_SYSVAR(queue_size_mb)
,	NULL
};

//----------------------------------------------------------------------------
// Stuff for system variables END
//============================================================================

static handler* pubsubsql_create_handler(handlerton* aHton, TABLE_SHARE* aTable, MEM_ROOT* aMemRoot) {
	DBUG_ENTER("ha_pubsubsql::pubsubsql_create_handler");
	handler* p = new (aMemRoot)PubsubsqlHandler(aHton, aTable);
	DBUG_RETURN(p);
}

static int pubsubsql_init(void* aPointer) {
	DBUG_ENTER("ha_pubsubsql::pubsubsql_init");
	PubsubsqlShare::onInit();
	handlerton* pubsubsql_hton = (handlerton*)aPointer;
	pubsubsql_hton->create = pubsubsql_create_handler;
	DBUG_RETURN(0);
}

static int pubsubsql_deinit(void* aPointer) {
	DBUG_ENTER("ha_pubsubsql::pubsubsql_deinit");
	PubsubsqlShare::onDeinit();
	DBUG_RETURN(0);
}

struct st_mysql_storage_engine pubsubsql_storage_engine =
{	MYSQL_HANDLERTON_INTERFACE_VERSION
};

mysql_declare_plugin(pubsubsql)
{	MYSQL_STORAGE_ENGINE_PLUGIN
	, &pubsubsql_storage_engine
	, "PUBSUBSQL"
	, "Mykhailo Oksenenko (mike@completedb.com)"
	, "PubSubSQL storage engine"
	, PLUGIN_LICENSE_GPL
	, pubsubsql_init		/* Plugin Init */
	, pubsubsql_deinit		/* Plugin Deinit */
	, 0x0100				/* 1.0 */
	, NULL					/* status variables */
	, pubsubsql_sys_vars	/* system variables */
	, NULL					/* config options */
	, 0						/* flags */
}
mysql_declare_plugin_end;
