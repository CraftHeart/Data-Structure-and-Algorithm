#pragma once
#ifndef DICTIONARY_H_
#define DICTIONARY_H_

template<class K, class E>
class Dictionary
{//
public:
	virtual ~Dictionary() {}
	//����ture �����ҽ����ֵ�Ϊ��
	virtual bool empty() const = 0;
	//�����ֵ������Եĸ���
	virtual int size() const = 0;
	//����ƥ�����Ե�ָ��
	virtual pair<const K, E> find(const K&) const = 0;
	//ɾ��ƥ��Ķ�
	virtual void erase(cosnt K&) = 0;
	//���ֵ��в������ԣ������ڣ��滻��
	virtual void insert(const pair<const K, E>&) = 0;
};

#endif // !DICTIONARY_H_
