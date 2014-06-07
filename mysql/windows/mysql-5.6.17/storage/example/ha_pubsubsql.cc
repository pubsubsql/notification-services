#include "ha_pubsubsql.h"

//============================================================================
// Stuff for system variables BEGIN
//----------------------------------------------------------------------------

static ulong pubsubsql_rows;
static ulong pubsubsql_queue_size_mb;

ulong PubsubsqlVariables::getRows() { return pubsubsql_rows; }
ulong PubsubsqlVariables::getQueueSizeMB() { return pubsubsql_queue_size_mb; }

static MYSQL_SYSVAR_ULONG
(	rows, pubsubsql_rows, 0
,	"Number of rows in the PubSubSQL engine tables"
,	NULL, NULL, 1, 0, 0, 0
);

static MYSQL_SYSVAR_ULONG
(	queue_size_mb, pubsubsql_queue_size_mb, 0
,	"Queue size (MB) in the PubSubSQL engine tables"
,	NULL, NULL, 1024, 0, 0, 0
);

//----------------------------------------------------------------------------

static struct st_mysql_sys_var* gPubsubsqlSystemVariables[] =
{	MYSQL_SYSVAR(rows)
,	MYSQL_SYSVAR(queue_size_mb)
,	NULL
};

//----------------------------------------------------------------------------
// Stuff for system variables END
//============================================================================

static handler* gPubsubsqlCreateHandler
(	handlerton* aHandlerton
,	TABLE_SHARE* aTable
,	MEM_ROOT* aMemRoot
) {
	DBUG_ENTER("PubsubsqlShare::gPubsubsqlCreateHandler");
	//
	handler* pubsubsqlHandler = new (aMemRoot)
		PubsubsqlHandler(aHandlerton, aTable);
	//
	DBUG_RETURN(pubsubsqlHandler);
}

static int gPubsubsqlInit(void* aHandlertonPointer) {
	DBUG_ENTER("ha_pubsubsql::gPubsubsqlInit");
	PubsubsqlShare::onInit(aHandlertonPointer);
	//
	handlerton* pubsubsqlHandlerton = (handlerton*)aHandlertonPointer;
	pubsubsqlHandlerton->create = gPubsubsqlCreateHandler;
	pubsubsqlHandlerton->state = SHOW_OPTION_YES;
	pubsubsqlHandlerton->flags = HTON_NO_PARTITION;
	//
	DBUG_RETURN(0);
}

static int gPubsubsqlDeinit(void* aHandlertonPointer) {
	DBUG_ENTER("ha_pubsubsql::gPubsubsqlDeinit");
	PubsubsqlShare::onDeinit(aHandlertonPointer);
	DBUG_RETURN(0);
}

struct st_mysql_storage_engine gPubsubsqlStorageEngine =
{	MYSQL_HANDLERTON_INTERFACE_VERSION
};

mysql_declare_plugin(pubsubsql)
{	MYSQL_STORAGE_ENGINE_PLUGIN
,	&gPubsubsqlStorageEngine
,	"PUBSUBSQL"
,	"Mykhailo Oksenenko (mike@completedb.com)"
,	"PubSubSQL storage engine"
,	PLUGIN_LICENSE_GPL
,	gPubsubsqlInit				/* Plugin Init */
,	gPubsubsqlDeinit			/* Plugin Deinit */
,	0x0100						/* 1.0 */
,	NULL						/* status variables */
,	gPubsubsqlSystemVariables	/* system variables */
,	NULL						/* config options */
,	0							/* flags */
}
mysql_declare_plugin_end;
