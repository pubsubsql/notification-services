#include "PubsubsqlList.hpp"

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

size_t PubsubsqlList::getCount() const {
	return mCount;
}

void PubsubsqlList::push(const char* aString) {
	PubsubsqlListNodeSptr newTail =
		PubsubsqlListNodeSptr(newPubsubsqlListNode(aString), deletePubsubsqlListNode);
	//
	if (newTail) {
		if (mTail) {
			mTail->setNext(newTail);
		}
		else {
			mHead = newTail;
		}
		mTail = newTail;
		mCount++;
	}
}

PubsubsqlListNodeSptr PubsubsqlList::pop() {
	PubsubsqlListNodeSptr oldHead = mHead;
	if (oldHead) {
		PubsubsqlListNodeSptr newHead = oldHead->getNext();
		if (newHead) {
			mHead = newHead;
		}
		else {
			mHead = nullptr;
			mTail = nullptr;
		}
		oldHead->setNext(nullptr);
		if (mCount > 0) {
			mCount--;
		}
	}
	return oldHead;
}

PubsubsqlListNodeSptr PubsubsqlList::peek() {
	return mHead;
}

PubsubsqlList::~PubsubsqlList() {
	// void
}

PubsubsqlList::PubsubsqlList()
:	mHead(nullptr)
,	mTail(nullptr)
,	mCount(0)
{
	// void
}
