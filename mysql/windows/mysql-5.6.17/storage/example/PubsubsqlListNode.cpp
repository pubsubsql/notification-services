#include "PubsubsqlListNode.hpp"

#include "mysql_version.h"
#include "my_global.h"                   /* ulonglong */
#include "thr_lock.h"                    /* THR_LOCK, THR_LOCK_DATA */
#include "handler.h"                     /* handler */
#include "my_base.h"                     /* ha_rows */

#include <cstring>

//----------------------------------------------------------------------------

PubsubsqlListNode* newPubsubsqlListNode(const char* aString) {
	//
	const char* str = (nullptr == aString ? "" : aString);
	size_t strLen = strlen(str);
	size_t strSizeB = (strLen + 1) * sizeof(char);
	//
	size_t nodeSizeB = sizeof(PubsubsqlListNode) + strSizeB;
	void* node = my_malloc(nodeSizeB, MYF(MY_WME));
	if (node) {
		return new (node)PubsubsqlListNode(nodeSizeB, str, strLen);
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

PubsubsqlListNode::PubsubsqlListNode(const size_t aNodeSizeB, const char* aString, const size_t aStringLen)
:	mSizeB(aNodeSizeB)
,	mStringLen(aStringLen)
,	mNext(nullptr)
{
	char* dst = static_cast<char*>(getPayload());
	strncpy(dst, aString, aStringLen);
	dst[aStringLen] = '\0'; // guard
}
