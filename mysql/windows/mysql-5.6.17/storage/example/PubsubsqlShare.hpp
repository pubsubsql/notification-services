#ifndef PUBSUBSQL_SHARE_HPP
#define PUBSUBSQL_SHARE_HPP

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

class PubsubsqlShare {

public: // fields

	char* mTableName;
	uint mTableNameLength;
	uint mUseCount;
	mysql_mutex_t mMutex;
	THR_LOCK mLock;

public: // iface

	static PubsubsqlShare* findOrCreateShare(const char* aTableName, TABLE* aTable);

	static void onInit();
	static void onDeinit();

public: // factory

	~PubsubsqlShare();
	PubsubsqlShare();

};

#endif /* PUBSUBSQL_SHARE_HPP */
