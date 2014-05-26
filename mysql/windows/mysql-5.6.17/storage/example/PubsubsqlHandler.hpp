#ifndef PUBSUBSQL_HANDLER_HPP
#define PUBSUBSQL_HANDLER_HPP

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

#include "PubsubsqlShare.hpp"

class PubsubsqlHandler : public handler {

private: // fields

	THR_LOCK_DATA mLock;		/* MySQL lock */
	PubsubsqlShare* mShare;		/* Shared lock info */

public: // factory

	virtual ~PubsubsqlHandler();
	PubsubsqlHandler(handlerton* aHton, TABLE_SHARE* aTable);

public: // iface

	virtual const char* table_type() const;
	virtual const char** bas_ext() const;
	virtual Table_flags table_flags() const;
	virtual ulong index_flags(uint aIdx, uint aPart, bool aAllParts) const;

	virtual int create(const char* aName, TABLE* aForm, HA_CREATE_INFO* aInfo);
	virtual int open(const char* aName, int aMode, uint aTestIfLocked);
	virtual int close();

	virtual int rnd_next(uchar* aBuf);
	virtual int rnd_pos(uchar* aBuf, uchar* aPos);
	virtual void position(const uchar* aRecord);
	virtual int info(uint);
	virtual THR_LOCK_DATA** store_lock(THD* aThd, THR_LOCK_DATA** aTo, enum thr_lock_type aLockType);
	virtual int rnd_init(bool aScan);

};

#endif /* PUBSUBSQL_HANDLER_HPP */
