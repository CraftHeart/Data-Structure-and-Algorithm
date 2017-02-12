#pragma once
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include<iostream>
using namespace std;

/*线性表的抽象类*/
template<class T>
class linearList
{
public:
	virtual ~linearList() {};
	virtual bool empty() const = 0;
	//返回ture，当且仅当线性表位空
	virtual bool full() const=0;
	//返回ture，当且仅当线性表满了
	virtual int size() const = 0;
	//返回线性表的元素个数
	virtual T& get(int theIndex) const = 0;
	//返回索引为theIndex的元素
	virtual int indexOf(const T& theElement) const = 0;
	//返回元素theElement第一次出现时的索引
	virtual void erase(int theIndex) = 0;
	//删除索引theIndex的元素
	virtual void insert(int theIndex, const T& theElement) = 0;
	//把theElement插入到线性表中索引为theIndex的位置上
	virtual void output(ostream& out) const = 0;
	//把线性表插入输出流out
};
#endif // !LINEARLIST_H
