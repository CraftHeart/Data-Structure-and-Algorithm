#pragma once
#ifndef STACK_H_
#define STACK_H_

template<class T>
class Stack
{
public:
	Stack() {}
	virtual void Push(const T&) = 0;
	virtual T& Pop() = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual int Size() const = 0;
	virtual ~Stack();
};

/********************sequeue stack************************/
template<class T>
class SeqStack: public Stack<T>
{
public:
	SeqStack(int max_size = 50) :max_size_{max_size} {}
	void Push(const T&);
	T& Pop();
	bool IsEmpty() const { return top==-1; }
	bool IsFull() const { return top == (max_size_ - 1); }
	int Size() const;
private:
	T* element_;
	int top_;
	int max_size_;
};

/*********************************************************/

/***********************list stack***************************/
template<class T>
class ListStack: public Stack<T>
{

};

/*********************************************************/

#endif // !STACK_H_
