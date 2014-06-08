#ifndef PUBSUBSQL_LIST_NODE_HPP
#define PUBSUBSQL_LIST_NODE_HPP

#include <cstdint>

class PubsubsqlListNode {

private: // fields

	uint64_t mSizeB;
	PubsubsqlListNode* mNext;

public: // iface

	inline uint64_t getSizeB() const { return mSizeB; }
	inline PubsubsqlListNode* getNext() { return mNext; }

	inline void* getPayload() { return ((uint8_t*)this) + sizeof(PubsubsqlListNode); }
	inline uint64_t getPayloadSizeB() const { mSizeB - sizeof(PubsubsqlListNode); }

public: // factory

	~PubsubsqlListNode();
	PubsubsqlListNode();

};

#endif /* PUBSUBSQL_LIST_NODE_HPP */
