#pragma once
#ifndef CIRCLE_DOUBLY_LINKED_LIST_H_
#define CIRCLE_DOUBLY_LINKED_LIST_H_

#include"myExceptions.h"

template<class T>
class CircleNode
{
public:
	CircleNode() {}
	CircleNode(const T& the_element,
		 CircleNode<T>* pre_node,
		 CircleNode<T>* next_node) :
		element_{ the_element }, pre_node_{ pre_node }, next_node_{ next_node } {}
public:
	T element_;
	CircleNode<T>* pre_node_;
	CircleNode<T>* next_node_;
};

template<class T>
class CircleDoublyLinkedList
{
public:
	//constructor
	CircleDoublyLinkedList() :list_size_{ 0 }, head_node_{ nullptr } {}
	CircleDoublyLinkedList(CircleDoublyLinkedList<T>&);
	~CircleDoublyLinkedList();

	//ADT
	bool is_empty()const { return list_size_ == 0; }
	T& operator[](const int the_index) const;
	CircleDoublyLinkedList<T>& operator=(CircleDoublyLinkedList<T> &);
	CircleDoublyLinkedList<T>& push_back(const T& the_element);
	CircleDoublyLinkedList<T>& push_begin(const T& the_element);
	CircleDoublyLinkedList<T>& insert(const int the_index, const T& the_element);
	CircleDoublyLinkedList<T>& erase(const int the_index);

private:
	void CheckIndex(const int the_index)const;
	int list_size_;
	CircleNode<T>* head_node_;
};

template<class T>
CircleDoublyLinkedList<T>::CircleDoublyLinkedList(CircleDoublyLinkedList<T>& the_list) :list_size_{0}
{
	CircleNode<T>* current_node = the_list.head_node_->next_node_;
	do {
		push_back(current_node->element_);
		current_node = current_node->next_node_;
	} while (current_node != the_list.head_node_);
}

template<class T>
CircleDoublyLinkedList<T>::~CircleDoublyLinkedList()
{
	CircleNode<T>* current_node = head_node_;
	for (int i = 0; i < list_size_-1; i++)
	{
		current_node = current_node->next_node_;
		delete[] head_node_;
		head_node_ = current_node;
	}
	delete[] head_node_;
	head_node_ = nullptr;
	list_size_ = 0;
}

template<class T>
void CircleDoublyLinkedList<T>::CheckIndex(const int the_index)const
{
	if (the_index < 0 || the_index >= list_size_)
		throw illegalIndex();
}

template<class T>
T& CircleDoublyLinkedList<T>::operator[](const int the_index) const
{
	CheckIndex(the_index);

	CircleNode<T>* current_node = head_node_;
	for (int i = 0; i < the_index; i++)
		current_node = current_node->next_node_;
	return current_node->element_;
}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::operator=(CircleDoublyLinkedList<T>& the_list)
{
	//clear old memory
	CircleNode<T>* this_current_node = head_node_;
	for (int i = 0; i < list_size_-1; i++)
	{
		this_current_node = this_current_node->next_node_;
		delete[] head_node_;
		head_node_ = this_current_node;
	}
	delete[] head_node_;
	head_node_ = nullptr;
	list_size_ = 0;

	//copy assignment
	CircleNode<T>* the_list_node = the_list.head_node_;
	do 
	{
		push_back(the_list_node->element_);
		the_list_node = the_list_node->next_node_;
	} while (the_list_node != the_list.head_node_);
	return *this;
}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::push_back(const T& the_element)
{
	if (list_size_ == 0)
	{
		head_node_ = new CircleNode<T>(the_element, nullptr, nullptr);
		head_node_->next_node_ = head_node_;
		head_node_->pre_node_ = head_node_;
		list_size_++;
	}
	else
	{
		CircleNode<T>* old_head_pre_node = head_node_->pre_node_;
		head_node_->pre_node_ = new CircleNode<T>(the_element, head_node_->pre_node_, head_node_);
		old_head_pre_node->next_node_ = head_node_->pre_node_;
		list_size_++;
	}
	return *this;
}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::push_begin(const T& the_element)
{
	if (list_size_ == 0)
	{
		head_node_ = new CircleNode<T>(the_element, nullptr, nullptr);
		head_node_->next_node_ = head_node_;
		head_node_->pre_node_ = head_node_;
		list_size_++;
	}
	else
	{
		CircleNode<T>* old_head_node = head_node_;
		head_node_ = new CircleNode<T>(the_element, head_node_->pre_node_, head_node_);
		old_head_node->pre_node_->next_node_ = head_node_;
		old_head_node->pre_node_ = head_node_;
		
		list_size_++;
	}
	return *this;
}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::insert(const int the_index, const T& the_element)
{
	//check index
	if (the_index<0 || the_index>list_size_)
		throw illegalIndex();

	//insert
	if (list_size_ == 0)
	{
		head_node_ = new CircleNode<T>(the_element, nullptr, nullptr);
		head_node_->next_node_ = head_node_;
		head_node_->pre_node_ = head_node_;
		list_size_++;
	}
	else
	{
		if (the_index == 0)
			push_begin(the_element);
		else if (the_index == list_size_)
			push_back(the_element);
		else
		{
			CircleNode<T>* current_node = head_node_;
			for (int i = 0; i < the_index; i++)
				current_node = current_node->next_node_;
			CircleNode<T>* old_current_node = current_node;
			current_node = new CircleNode<T>(the_element, current_node->pre_node_, current_node);
			old_current_node->pre_node_ = current_node;
			old_current_node->pre_node_->pre_node_->next_node_ = current_node;
			list_size_++;
		}
	}
	return *this;
}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::erase(const int the_index)
{
	//Check index
	CheckIndex(the_index);

	//erase
	CircleNode<T>* current_node = head_node_;
	for (int i = 0; i < the_index; i++)
		current_node = current_node->next_node_;
	current_node->next_node_->pre_node_ = current_node->pre_node_;
	current_node->pre_node_->next_node_ = current_node->next_node_;
	delete[] current_node;
	list_size_--;
	return *this;
}
#endif // !CIRCLE_DOUBLY_LINKED_LIST_H_
