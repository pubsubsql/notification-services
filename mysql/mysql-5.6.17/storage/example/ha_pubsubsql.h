#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

#include "PubsubsqlHandler.hpp"
#include "PubsubsqlShare.hpp"

class PubsubsqlVariables {

public: // iface

	static ulong getRows();
	static ulong getQueueSizeMB();

};
