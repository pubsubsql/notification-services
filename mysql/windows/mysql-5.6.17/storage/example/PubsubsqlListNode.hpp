#ifndef PUBSUBSQL_LIST_NODE_HPP
#define PUBSUBSQL_LIST_NODE_HPP

#include <memory>
#include <cstdlib>

class PubsubsqlListNode;
typedef std::shared_ptr<PubsubsqlListNode> PubsubsqlListNodeSptr;

//----------------------------------------------------------------------------

PubsubsqlListNode* newPubsubsqlListNode(const char* aString);
void deletePubsubsqlListNode(PubsubsqlListNode* aNode);

//----------------------------------------------------------------------------

class PubsubsqlListNode {

private: // fields

	size_t mSizeB;
	size_t mStringLen;
	PubsubsqlListNodeSptr mNext;

public: // iface

	inline size_t getSizeB() const { return mSizeB; }
	inline PubsubsqlListNodeSptr getNext() { return mNext; }
	inline void setNext(PubsubsqlListNodeSptr aNext) { mNext = aNext; }
	//
	inline void* getPayload() { return ((uint8_t*)this) + sizeof(PubsubsqlListNode); }
	inline size_t getPayloadSizeB() const { return (mSizeB - sizeof(PubsubsqlListNode)); }
	//
	inline const char* c_str() { return static_cast<char*>(getPayload()); }
	inline size_t c_str_len() const { return mStringLen; }

public: // factory

	~PubsubsqlListNode();
	PubsubsqlListNode(const size_t aNodeSizeB, const char* aString, const size_t aStringLen);

};

#endif /* PUBSUBSQL_LIST_NODE_HPP */
