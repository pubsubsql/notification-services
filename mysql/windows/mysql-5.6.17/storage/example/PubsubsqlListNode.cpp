#include "PubsubsqlListNode.hpp"

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

//----------------------------------------------------------------------------

PubsubsqlListNode* newPubsubsqlListNode() {
	void* node = my_malloc(sizeof(PubsubsqlListNode), MYF(MY_WME));
	if (node) {
		return new (node)PubsubsqlListNode();
	}
	else {
		return nullptr;
	}
}

void deletePubsubsqlListNode(PubsubsqlListNode* aNode) {
	if (aNode) {
		aNode->~PubsubsqlListNode();
		my_free(aNode);
	}
}

//----------------------------------------------------------------------------

PubsubsqlListNode::~PubsubsqlListNode() {
	// void
}

PubsubsqlListNode::PubsubsqlListNode()
:	mSizeB(sizeof(PubsubsqlListNode))
,	mNext(nullptr)
{
	// void
}
