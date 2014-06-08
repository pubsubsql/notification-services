#ifndef PUBSUBSQL_LIST_HPP
#define PUBSUBSQL_LIST_HPP

#include "PubsubsqlListNode.hpp"

#include <cstdlib>

class PubsubsqlList {

private: // fields

	PubsubsqlListNodeSptr mHead;
	PubsubsqlListNodeSptr mTail;
	size_t mCount;

public: // iface

	size_t getCount() const;
	void push();
	PubsubsqlListNodeSptr pop();
	PubsubsqlListNodeSptr peek();

public: // factory

	~PubsubsqlList();
	PubsubsqlList();

};

#endif /* PUBSUBSQL_LIST_HPP */
