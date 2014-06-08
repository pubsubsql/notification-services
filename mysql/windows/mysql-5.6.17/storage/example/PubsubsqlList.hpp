#ifndef PUBSUBSQL_LIST_HPP
#define PUBSUBSQL_LIST_HPP

#include "PubsubsqlListNode.hpp"

class PubsubsqlList {

private: // fields

	PubsubsqlListNodeSptr mHead;
	PubsubsqlListNodeSptr mTail;

public: // iface

	void push();
	PubsubsqlListNodeSptr pop();
	PubsubsqlListNodeSptr peek();

public: // factory

	~PubsubsqlList();
	PubsubsqlList();

};

#endif /* PUBSUBSQL_LIST_HPP */
