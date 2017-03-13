#pragma once
#ifndef  MAX_HEAP_H_
#define MAX_HEAP_H_

#include"max_priority_queue.h"
#include"myExceptions.h"

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
	heap_size_ = 0;
	heap_capacity_ = initial_capacity;
	heap_ = new T[heap_capacity_];
}

template<class T>
void MaxHeap<T>::pop()
{

}


#endif // ! MAX_HEAP_H_
