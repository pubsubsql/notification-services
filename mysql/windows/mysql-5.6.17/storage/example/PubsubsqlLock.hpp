#ifndef PUBSUBSQL_LOCK_HPP
#define PUBSUBSQL_LOCK_HPP

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

class PubsubsqlLock {

public: // factory

	~PubsubsqlLock();
	PubsubsqlLock();

};

#endif /* PUBSUBSQL_LOCK_HPP */
