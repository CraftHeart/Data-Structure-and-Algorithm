#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_

#include"myExceptions.h"
#include"chainNode.h"

template<class T>
class Queue
{
public:
	virtual ~Queue() {}

	virtual bool empty() const = 0;

	virtual int size() const = 0;//返回队列中元素个数

	virtual T& front() const = 0;//返回队头元素的引用

	virtual T& back() const = 0;//返回队尾元素的引用

	virtual void pop() = 0;//弹出队头元素

	virtual void push(const T& the_element) = 0;//入队操作

};

/*************ArrayQueue*****************/
template<class T>
class ArrayQueue:public Queue<T>
{
public:
	ArrayQueue(int initial_capacity = 10)
	{
		if (initial_capacity < 1)
			throw ThrowException("initial capacity should > 0 ");
		queue_= new T[initial_capacity];
		queue_front_ = 0;
		queue_back_ =0;
		queue_length_ = initial_capacity;
	}

	~ArrayQueue()
	{
		delete[] queue_;
	}

	bool empty() const { return queue_front_ == queue_back_; }

	bool full() const { return queue_length_ - 1 == size(); }

	int size() const { return (queue_back_-queue_front_+queue_length_)%queue_length_ ; }

	T& front() const
	{
		if (empty())
			throw  ThrowException("front error: queue is empty");
		return queue_[(queue_front_+1)%queue_length_];
	}

	T& back() const
	{
		if(empty())
			throw  ThrowException("back error: queue is empty");
		return queue_[queue_back_];
	}

	void pop();

	void push(const T& the_element);

private:
	int queue_length_; // queue capacity
	int queue_front_;  // 1 counterclockwise from theFront element
	int queue_back_;  // position of theBack element
	T* queue_;  //element array
};

template<class T>
void ArrayQueue<T>::pop()
{
	if (empty())
		throw  ThrowException("back error: queue is empty");
	//queue_front向前移动一位
	queue_front_ = (queue_front_ + 1) % queue_length_;
	//调用队头元素的析构函数
	queue_[queue_front_].~T();
}

template<class T>
void ArrayQueue<T>::push(const T& the_element)
{
	if (full())
	{// if is full ,double the capacity of the queue
		//allocate a new array
		T* new_queue = new T[2 * queue_length_];

		//copy the element to new queue
		int start = (queue_front_ + 1) % queue_length_;
		if (start < 2)
			copy(queue_ + start, queue_ - start + queue_length_ - 1,new_queue);
		else
		{
			copy(queue_ + start, queue_  + queue_length_-1, new_queue);
			copy(queue_, queue_ + queue_back_ , new_queue + queue_length_ - start);
		}
		queue_front_ = 2 * queue_length_ - 1;
		queue_back_ = queue_length_ - 2;
		delete[] queue_;
		queue_ = new_queue;
		queue_length_ = 2 * queue_length_;
	}
	queue_back_ = (queue_back_ + 1) % queue_length_;
	queue_[queue_back_] = the_element;
}
/****************************************/

/***************ListQueue*****************/
template<class T>
class ListQueue :public Queue<T>
{
public:
	ListQueue()
	{
		queue_back_ = nullptr;
		queue_front_ = nullptr;
		queue_size_ = 0;
	}

	~ListQueue();

	bool empty() const { return queue_front_ == nullptr; }

	int size() const { return queue_size_; }

	T& front() const
	{
		if (empty())
			throw ThrowException("front error: queue is empty");
		return queue_front_->element;
	}

	T& back() const
	{
		if (empty())
			throw ThrowException("front error: queue is empty");
		return queue_back_->element;
	}

	void pop();

	void push(const T& the_element);

private:
	chainNode<T>* queue_front_;
	chainNode<T>* queue_back_;
	int queue_size_;
};

template<class T>
ListQueue<T>::~ListQueue()
{
	chainNode<T>* current_node = queue_front_->next;
	do
	{
		delete queue_front_;
		queue_front_ = current_node;
		current_node = current_node->next;
	} while (queue_front_ == queue_back_);
}

template<class T>
void ListQueue<T>::pop()
{
	if (empty())
		throw ThrowException("front error: queue is empty");
	chainNode<T>* old_front_next = queue_front_->next;
	delete queue_front_;
	queue_front_ = old_front_next;
	queue_size_--;
}

template<class T>
void ListQueue<T>::push(const T& the_element)
{
	if (queue_size_ == 0)
	{
		queue_front_ = new chainNode<T>(the_element, nullptr);
		queue_back_ = queue_front_;
		queue_size_++;
	}
	else
	{
		chainNode<T>* old_back = queue_back_;
		queue_back_ = new chainNode<T>(the_element, nullptr);
		old_back->next = queue_back_;
		queue_size_++;
	}
}

/****************************************/


#endif // !QUEUE_H_
