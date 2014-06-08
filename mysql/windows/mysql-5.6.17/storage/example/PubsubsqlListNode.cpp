#include "PubsubsqlListNode.hpp"

PubsubsqlListNode::~PubsubsqlListNode() {
	// void
}

PubsubsqlListNode::PubsubsqlListNode()
:	mSizeB(sizeof(PubsubsqlListNode))
,	mNext(nullptr)
{
	// void
}
