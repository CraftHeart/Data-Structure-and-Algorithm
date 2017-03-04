#pragma once
#ifndef DICTIONARY_H_
#define DICTIONARY_H_

template<class K, class E>
class Dictionary
{
public:
	virtual ~Dictionary() {}
	//返回ture ，当且仅当字典为空
	virtual bool empty() const = 0;
	//返回字典中数对的个数
	virtual int size() const = 0;
	//返回匹配数对的指针
	virtual pair<const K, E> find(const K&) const = 0;
	//删除匹配的对
	virtual void erase(cosnt K&) = 0;
	//往字典中插入数对，若存在，替换它
	virtual void insert(const pair<const K, E>&) = 0;
};

#endif // !DICTIONARY_H_
