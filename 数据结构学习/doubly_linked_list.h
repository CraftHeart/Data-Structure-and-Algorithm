#pragma once
#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include<iostream>
#include"myExceptions.h"

using namespace std;

//the node class
template<class T>
class Node
{
public:
	Node(){}
	Node(const T& element, 
				 Node<T>* pre_node, 
				 Node<T>* next_node) 
				:element_{ element }, 
				pre_node_{ pre_node }, 
				next_node_{ next_node } {}
public:
	T element_;
	Node<T>* pre_node_;
	Node<T>* next_node_;
};

//the doubly linked list class
template<class T>
class DoublyLinkedList
{
public:
	//constructor and destructor
	DoublyLinkedList();
	~DoublyLinkedList();

	//ADT
	bool is_empty() const { return list_size_ == 0; }
	int size() const { return list_size_; }
	T& operator[](const int the_index) const;
	void push_back(const T& the_element);
	void push_begin(const T& the_element);
	void insert(int the_index, const T& the_element);
	void erase(int the_index);

private:
	void check_index(int the_index) const;
	Node<T>* first_node_;
	Node<T>* last_node_;
	int list_size_;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() :first_node_{ nullptr },
																				last_node_{ nullptr },
																				list_size_{ 0 } {}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node<T>* current_node = first_node_;
	for (int i = 0; i < list_size_-1; i++)
	{
		current_node = current_node->next_node_;
		delete[] first_node_;
		first_node_ = current_node;
	}
	delete[] last_node_;
}

template<class T>
void DoublyLinkedList<T>::check_index(int the_index) const
{
	if (the_index < 0 || the_index >= list_size_)
		throw illegalIndex();
}

template<class T>
T& DoublyLinkedList<T>::operator[](const int the_index) const
{
	//while the index < list_size/2, we search start at the first node;
	//while the index > list_size/2, we search start at the last node;
	if (the_index <= list_size_ / 2)
	{
		Node<T>* current_node = first_node_;
		for (int i = 0; i < the_index; i++)
			current_node = current_node->next_node_;
		return current_node->element_;
	}
	else
	{
		Node<T>* current_node = first_node_;
		for (int i = list_size_-1; i > the_index; i--)
			current_node = current_node->pre_node_;
		return current_node->element_;
	}
}

template<class T>
void DoublyLinkedList<T>::push_back(const T& the_element)
{
	if (list_size_ > 0)
	{
		Node<T>* old_last_node = last_node_;
		last_node_ = new Node<T>(the_element, last_node_, nullptr);
		old_last_node->next_node_ = last_node_;
		list_size_++;
	}
	else
	{
		first_node_ = new Node<T>(the_element, nullptr, nullptr);
		last_node_ = first_node_;
		list_size_++;
	}
}

template<class T>
void DoublyLinkedList<T>::push_begin(const T& the_element)
{
	if (list_size_ > 0)
	{
		Node<T>* old_first_node = first_node_;
		first_node_ = new Node<T>(the_element, nullptr, first_node_);
		old_first_node->pre_node_ = first_node_;
		list_size_++;
	}
	else
	{
		first_node_ = new Node<T>(the_element, nullptr, nullptr);
		last_node_ = first_node_;
		list_size_++;
	}
}



template<class T>
void DoublyLinkedList<T>::insert(int the_index, const T& the_element)
{
	//check the index
	if (the_index<0 || the_index>list_size_)
		throw illegalIndex();
	if (list_size_ == 0)
	{
		first_node_ = new Node<T>(the_element, nullptr, nullptr);
		last_node_ = first_node_;
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
			Node<T>* current_node = first_node_;
			for (int i = 0; i < the_index; i++)
				current_node = current_node->next_node_;
			Node<T>* old_current_node = current_node;
			current_node = new Node<T>(the_element, current_node->pre_node_, current_node);
			old_current_node->next_node_->pre_node_ = current_node;
			old_current_node->pre_node_->next_node_ = current_node;
			list_size_++;
		}
	}
}

template<class T>
void DoublyLinkedList<T>::erase(int the_index)
{
	//check the index
	check_index(the_index);

	if (the_index <= list_size_ / 2)
	{
		if (the_index == 0)
		{
			first_node_ = first_node_->next_node_;
			delete[] first_node_->pre_node_;
			list_size_--;
		}
		else
		{
			Node<T>* current_node = first_node_;
			for (int i = 0; i < the_index; i++)
				current_node = current_node->next_node_;
			current_node->pre_node_->next_node_ = current_node->next_node_;
			current_node->next_node_->pre_node_ = current_node->pre_node_;
			delete[] current_node;
			list_size_--;
		}
	}
	else
	{
		if (the_index == list_size_ - 1)
		{
			last_node_ = last_node_->pre_node_;
			delete[] last_node_->next_node_;
			list_size_--;
		}
		else
		{
			Node<T>* current_node = last_node_;
			for (int i = list_size_-1; i > the_index; i--)
				current_node = current_node->pre_node_;
			current_node->next_node_->pre_node_ = current_node->pre_node_;
			current_node->pre_node_->next_node_ = current_node->next_node_;
			delete[] current_node;
			list_size_--;
		}
	}
}



#endif // !DOUBLY_LINKED_LIST_H_
