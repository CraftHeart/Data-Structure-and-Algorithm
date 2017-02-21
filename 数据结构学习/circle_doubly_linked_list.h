#pragma once
#ifndef CIRCLE_DOUBLY_LINKED_LIST_H_
#define CIRCLE_DOUBLY_LINKED_LIST_H_

template<T>
class CircleNode
{
public:
private:
	T element_;
	CircleNode<T>* pre_node_:
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

	bool is_empty()const { return list_size_ == 0; }
	T& operator[](const int the_index) const;
	CircleDoublyLinkedList<T>& operator=(CircleDoublyLinkedList<T> &);
	CircleDoublyLinkedList<T>& push_back(const T& the_element);
	CircleDoublyLinkedList<T>& push_begin(const T& the_element);
	CircleDoublyLinkedList<T>& insert(const int the_index, const T& the_element);
	CircleDoublyLinkedList<T>& erase(const int the_index);

private:
	int list_size_;
	CircleNode<T>* head_node_;
};

template<class T>
CircleDoublyLinkedList<T>::CircleDoublyLinkedList(CircleDoublyLinkedList<T>& the_list)
{

}

template<class T>
CircleDoublyLinkedList<T>::~CircleDoublyLinkedList()
{
	CircleNode<T>* current_node = head_node_;

}

template<class T>
T& CircleDoublyLinkedList<T>::operator[](const int the_index) const
{

}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::operator=(CircleDoublyLinkedList<T>& the_list)
{

}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::push_back(const T& the_element)
{

}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::push_begin(const T& the_element)
{

}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::insert(const int the_index, const T& the_element)
{

}

template<class T>
CircleDoublyLinkedList<T>& CircleDoublyLinkedList<T>::erase(const int the_index)
{

}
#endif // !CIRCLE_DOUBLY_LINKED_LIST_H_
