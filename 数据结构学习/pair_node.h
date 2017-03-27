#pragma once
#ifndef PAIR_NODE_H_
#define PAIR_NODE_H_

using namespace std;

template<class K, class E >
struct PairNode
{
	//ÄÚÇ¶ÀàÐÍ
	typedef pair<const K, E> PairType;
	typedef PairType* Pointer;
	typedef PairType& Reference;

	PairType element_;
	PairNode* next_;

	PairNode(const Reference the_pair) :element_{ the_pair } {}
	PairNode(const Reference the_pair, PairNode<K,E>* the_next)
		: element_{ the_pair }, next_{ the_next } {}
};
#endif // !PAIR_NODE_H_
