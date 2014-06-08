#ifndef PUBSUBSQL_LIST_NODE_HPP
#define PUBSUBSQL_LIST_NODE_HPP

#include <memory>

class PubsubsqlListNode;
typedef std::shared_ptr<PubsubsqlListNode> PubsubsqlListNodeSptr;

//----------------------------------------------------------------------------

PubsubsqlListNode* newPubsubsqlListNode();
void deletePubsubsqlListNode(PubsubsqlListNode* aNode);

//----------------------------------------------------------------------------

class PubsubsqlListNode {

private: // fields

	size_t mSizeB;
	PubsubsqlListNodeSptr mNext;

public: // iface

	inline size_t getSizeB() const { return mSizeB; }
	inline PubsubsqlListNodeSptr getNext() { return mNext; }
	inline void setNext(PubsubsqlListNodeSptr aNext) { mNext = aNext; }

	inline void* getPayload() { return ((uint8_t*)this) + sizeof(PubsubsqlListNode); }
	inline size_t getPayloadSizeB() const { mSizeB - sizeof(PubsubsqlListNode); }

public: // factory

	~PubsubsqlListNode();
	PubsubsqlListNode();

};

#endif /* PUBSUBSQL_LIST_NODE_HPP */
