#pragma once
//circularList list with header node

#ifndef SINGLYLINKEDCIRULARLIST_H_
#define SINGLYLINKEDCIRULARLIST_H_

#include<iostream>
#include<string>
#include"myExceptions.h"
#include"chainNode.h"


using namespace std;

template<class T>
class SinglyLinkedCircularList
{
public:
	//constructor
	SinglyLinkedCircularList();
	~SinglyLinkedCircularList();

	//some methods
	int size() const { return listSize; }
	T& get(int the_index) const;
	int index_of(const T& kTheElement) const;
	void Insert(int the_index, const T& kTheElement);
	void erase(int the_index);
	void output(ostream& out) const;

private:
	void CheckIndex(int the_index) const;
	chainNode<T>* header_node_;
	int list_size_;
};

template<class T>
SinglyLinkedCircularList<T>::SinglyLinkedCircularList()
{
	header_node_ = new chainNode<T>();
	header_node_->next = header_node_;
	list_size_ = 0;
}

template<class T>
SinglyLinkedCircularList<T>::~SinglyLinkedCircularList()
{
	chainNode<T>* next_node = header_node_->next;
	chainNode<T>* reference_node = header_node_->next;
	chainNode<T>* next_next_node = header_node_->next->next;
	while (next_next_node != reference_node)
	{
		delete next_node;
		next_node = next_next_node;
		next_next_node = next_next_node->next;
	}
	delete next_node;
}

template<class T>
void SinglyLinkedCircularList<T>::CheckIndex(int the_index) const
{
	if (the_index < 0 || the_index >= list_size_)
	{
		//ostringstream s;
		cout << "index = " << the_index << " size= " << list_size_;
		throw illegalIndex();
	}
}

template<class T>
T& SinglyLinkedCircularList<T>::get(int the_index) const
{
	CheckIndex(the_index);
	chainNode<T>* current_node = header_node_->next;
	for (int index = 0; index < the_index; index++)
		current_node = current_node->next;
	return current_node->element;
}

template<class T>
int SinglyLinkedCircularList<T>::index_of(const T& kTheElement) const
{
	header_node_->element = kTheElement;
	chainNode<T>* current_node = header_node_->next;
	int index = 0;
	while (current_node->element != kTheElement)
	{
		current_node = current_node->next;
		index++;
	}
	if (current_node == header_node_)
		return -1;
	else
		return index;
}

template<class T>
void SinglyLinkedCircularList<T>::Insert(int the_index, const T& kTheElement)
{
	if (the_index < 0 || the_index > list_size_)
	{
		//ostringstream s;
		cout << "index = " << the_index << " size= " << list_size_;
		throw illegalIndex();
	}

	chainNode<T>* new_node = header_node_;
	for (int i = 0; i < the_index; i++)
	{
		new_node = new_node->next;
	}
	new_node->next = new chainNode<T>(kTheElement, new_node->next);
	list_size_++;
 }

template<class T>
void SinglyLinkedCircularList<T>::erase(int the_index)
{
	CheckIndex(the_index);
	chainNode<T>* current_node = header_node_;
	for (int i = 0; i < the_index; i++)
	{
		current_node = current_node->next;
	}
	chainNode<T>* delete_node = current_node->next;
	current_node->next = current_node->next->next;

	delete delete_node;
	list_size_--;
 }

template<class T>
void SinglyLinkedCircularList<T>::output(ostream & out) const
{
	chainNode<T>* current_node = header_node_->next;
	while (current_node != header_node_)
	{
		out << current_node->element << " ";
		current_node = current_node->next;
	}
}
#endif // !SINGLYLINKEDCIRULARLIST_H_
