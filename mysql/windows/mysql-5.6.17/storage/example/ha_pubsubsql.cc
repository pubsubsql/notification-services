#include "ha_pubsubsql.h"

handler* pubsubsql_create_handler(handlerton* hton, TABLE_SHARE* table, MEM_ROOT* mem_root) {
	DBUG_ENTER("ha_pubsubsql::pubsubsql_create_handler");
	handler* p = new (mem_root)PubsubsqlHandler(hton, table);
	DBUG_RETURN(p);
}

int pubsubsql_init(void* p) {
	DBUG_ENTER("ha_pubsubsql::pubsubsql_init");
	handlerton* pubsubsql_hton = (handlerton *)p;
	pubsubsql_hton->create = pubsubsql_create_handler;
	DBUG_RETURN(0);
}
