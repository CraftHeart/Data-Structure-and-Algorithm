#pragma once
#ifndef MAX_PRIORITY_QUEUE_H_
#define MAX_PRIORITY_QUEUE_H_

template<class T>
class MaxPriorityQueue
{
public:
	virtual ~MaxPriorityQueue() {}

	virtual bool empty() const = 0;  //return ture if and only if the queue is empty

	virtual int size() const = 0; //return the number of the queue`s elements;

	virtual const T& top() = 0; //return the reference of the element having max priority

	virtual void pop() = 0;// delete the element having max priority

	virtual void push(const T& the_element) = 0;//insert the_element to the queue
};
#endif // !MAX_PRIORITY_QUEUE_H_
