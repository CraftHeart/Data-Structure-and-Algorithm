#pragma once
#ifndef SORTED_CHAIN_H_
#define SORTED_CHAIN_H_

#include<iostream>
#include"pair_node.h"
#include"dictionary.h"

using namespace std;

template<class K, class E>
class SortedChain :public Dictionary<K, E>
{
public:
	typedef pair<const K, E> PairType;
	typedef PairType* Pointer;
	typedef PairType& Reference;

public:
	SortedChain() { first_node_ = nullptr; d_size_ = 0; }
	~SortedChain();

	bool empty()const { return d_size_ == 0; }
	int size()const { return d_size_; }
	Pointer find(const K&) const;
	void erase(const K&);
	void insert(const Reference);
	void output(ostream& out)const;

private:
	PairNode<K,E>* first_node_; //pointer to the first node in chain
	int d_size_;  //number of elements in dictionary
};

template<class K, class E>
SortedChain<K, E>::~SortedChain()
{
	while (first_node_ != nullptr)
	{
		PairNode<K, E>* next_node = first_node_->next_;
		delete first_node_;
		first_node_ = next_node;
	}
}

template<class K,class E>
pair<const K,E>* SortedChain<K,E>::find(const K& the_key) const
{
	PairNode<K, E> * current_node = first_node_;
	while (current_node != nullptr&&
		current_node->element_.first != the_key)
		current_node = current_node->next_;
	//verify match
	if (current_node != nullptr&&current_node->element_.first == the_key)
		return &current_node->element_;
	// no match
	return nullptr;
}

template<class K,class E>
void SortedChain<K, E>::erase(const K& the_key)
{
	PairNode<K, E>* current_node = first_node_;
	PairNode<K, E>* current_node_last_node = nullptr;

	//search for 
	while (current_node != nullptr&&current_node->element_.first < the_key)
	{
		current_node_last_node = current_node;
		current_node = current_node->next_;
	}

	//删除关键字为the_key的节点
	if (current_node != nullptr&&current_node->element_.first == the_key)
	{
		if (current_node_last_node == nullptr) //若删除的是第一个节点
			first_node_ = current_node->next_;
		else//若不是第一个节点
			current_node_last_node->next_ = current_node->next_;

		delete current_node;
		d_size_--;
	}
}

template<class K,class E>
void SortedChain<K, E>::insert(const Reference the_pair)
{
	PairNode<K, E>* current_node = first_node_;
	PairNode<K, E>*  current_last = nullptr;

	while (current_node != nullptr&&current_node->element_.first < the_pair.first)
	{
		current_last = current_node;
		current_node = current_node->next_;
	}

	//check if there is matching pair
	if (current_node != nullptr&&current_node->element_.first == the_pair.first)
	{//has matching pair, instead the second
		current_node->element_.second = the_pair.second;
		return;
	}

	//no matching, set up node for pair
	PairNode<K, E> *new_node = new PairNode<K, E>(the_pair, current_node);

	if (current_last == nullptr) first_node = new_node;
	else current_last->next_ new_node;

	d_size_;
	return;
}

template<class K,class E>
void SortedChain<K, E>::output(ostream& out)const
{
	for (PairNode<K, E>* current_node = first_node_; current_node != nullptr;
		current_node = current_node->next_)
		out << current_node->element_.first << " "
		<< current_node->element_.second << " ";
}


#endif // !SORTED_CHAIN_H_
