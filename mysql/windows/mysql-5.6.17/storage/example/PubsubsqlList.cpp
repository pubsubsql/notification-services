#include "PubsubsqlList.hpp"

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

void PubsubsqlList::push() {
	PubsubsqlListNodeSptr newTail =
		PubsubsqlListNodeSptr(newPubsubsqlListNode(), deletePubsubsqlListNode);
	//
	if (newTail) {
		if (mTail) {
			mTail->setNext(newTail);
		}
		else {
			mHead = newTail;
		}
		mTail = newTail;
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
{
	// void
}
