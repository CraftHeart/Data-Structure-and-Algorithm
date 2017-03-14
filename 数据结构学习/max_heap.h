#pragma once
#ifndef  MAX_HEAP_H_
#define MAX_HEAP_H_

#include"max_priority_queue.h"
#include"myExceptions.h"
#include"change_array_length.h"

template<class T>
class MaxHeap :public MaxPriorityQueue
{
public:
	MaxHeap(int initial_capacity = 10);
	~MaxHeap() { deletep[] heap_; }

	bool empty() const { return heap_size_ == 0; }
	int size() const { return heap_size_; }
	const T& top() 
	{
		if (heap_size_ == 0)
			throw ThrowException("top error: heap is empty");
		return heap_[1];
	}
	void pop();
	void push(const T&);
	void initialize(T*, int);

private:
	int heap_size_;//number of the heap elements
	int heap_capacity_;//the capacity of the heap
	T* heap_; //element array
};

template<class T>
MaxHeap<T>::MaxHeap(int initial_capacity = 10)
{
	if (initial_capacity < 1)
	{
		cerr << "initial_capacity = " << initial_capacity << " must >0" << endl;
		exit(-1);
	}
	heap_size_ = 0;
	heap_capacity_ = initial_capacity;
	heap_ = new T[heap_capacity_];
}

//delete the element having max priority
template<class T>
void MaxHeap<T>::pop()
{
	if (heap_size_ == 0)
		throw ThrowException("heap queue is empty");

	//delete element
	heap_[1].~T();

	T last_element = heap_[heap_size_--];

	//find place for last element
	int current_node = 1;
	int current_child_node = 2;

	while (current_child_node < heap_size_)
	{
		//heap_[current_child_node] should be the max between thr children
		if (current_child_node < heap_size_&&heap_[current_child_node] < heap_[current_child_node + 1])
			current_child_node++;

		//can we put the last element in heap_[current_child_node]?
		if (last_element > heap_[current_child_node])
			break;
		//no
		heap_[current_node] = heap_[current_child_node];//move child up
		current_node = current_child_node;// move down a level
		current_child_node *= 2;
	}
	heap_[current_node] = last_element;
}

//push the element to the heap
template<class T>
void MaxHeap<T>::push(const T& the_element)
{
	//increase array length if necessary
	if (heap_size_ == heap_capacity_)
	{//double the array length
		ChangeArrayLength(heap_, heap_capacity_, 2 * heap_capacity_);
		heap_capacity_ *= 2;
	}

	//find place for the element
	int current_node = ++heap_size_;
	while (current_node != 1 && heap_[current_node / 2] < the_element)
	{
		heap_[current_node] = heap_[current_node / 2]; //move parent element down
		current_node /= 2; //move to parent
	}
	heap_[current_node] = the_element;
}

template<class T>
void MaxHeap<T>::initialize(T * the_heap, int heap_size)
{
	delete[] heap_;
	heap_ = the_heap;
	heap_size_ = heap_size;                 

	//heapify from the last node having child node
	for (int root = heap_size_ / 2; root >= 1; root--)
	{
		T root_element = heap_[root];

		//find place to put root element
		int child = 2 * root;

		while (child < heap_size_)
		{
			//heap[child] should be the larger one of children
			if (child < heap_size_&&heap_[child] < heap_[child + 1])
				child++;
			//can we put root element in heap[child/2]
			if (root_element >= heap_[child])
				break;
			//no
			heap_[child / 2] = heap_[child];
			child *= 2;
		}
		heap_[child / 2] = root_element;
	}
}


#endif // ! MAX_HEAP_H_
