#pragma once
#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include"linearList.h"
#include<iostream>
#include<ostream>
#include<algorithm>   //find()
#include<iterator>
using namespace std;

template<class T>
inline T Min(const T a, const T b)
{
	return a < b ? a : b;
}

/*��arrayList*/
//������linearList������
template<class T>
class arrayList :public linearList<T>
{
public:
	//arrayList���Ĺ��캯������������
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; }

	//ADT������������
	bool empty() const { return listSize == 0; }
	bool full() const { return listSize == arrayLength; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
	int capacity() const { return arrayLength; }

private:
	void checkIndex(int theIndex) const;	//������theIndex��Ч�����׳��쳣
	T* element;				//�洢���Ա�Ԫ�ص�һά����
	int arrayLength;		//һά����������
	int listSize;				//���Ա���Ԫ�صĸ���
};

//�ı�һ��һά�����ĳ���
template<class Tc>
void ChangeArrayLength(Tc*& str, int OldLength, int NewLength);

//�ı�һ��һά�����ĳ���
template<class Tc>
void ChangeArrayLength(Tc*& str, int OldLength, int NewLength)   //�˴�����Ҫ�ı�ָ�뱾����ֵ������Ҫ��ָ��������
{
	if (NewLength < 0)
		throw ("new length must be >= 0");
	int strSize = Min(OldLength, NewLength);
	Tc* temp = new Tc[strSize];

	copy(str, str + strSize, temp);
	delete[] str;
	str = temp;
}

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{//���캯��
	if (initialCapacity < 1)
	{
		//ostringstream s;
		cout << "Initial capacity = " << initialCapacity << "Must be >0";
		exit(-1);
		//throw s;
	}
	arrayLength = initialCapacity;
	element = new T[initialCapacity];
	listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	copy(theList.element, theList.element + theList.listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{//ȷ������theIndex��0��listSzie-1֮��
	if (theIndex < 0 || theIndex > listSize)
	{
		//ostringstream s;
		cout << "index = " << theIndex << " size = " << listSize;
		exit(-1);
		//throw s;
	}
}

template<class T>
T& arrayList<T>::get(int theIndex) const
{//��������ΪtheIndex��Ԫ��
 //��Ԫ�ز����ڣ����׳��쳣
	checkIndex(theIndex);
	return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{//����Ԫ��theElement�ĵ�һ�γ��ֵ�����
 //�������ڴ�Ԫ�أ��򷵻�-1

 //����Ԫ��theElement
 //find()���ҳɹ�����һ��ָ��ָ��Ԫ�صĵ�����������ʧ�ܷ���end������
	int theIndex = (int)(find(element, element + listSize, theElement) - element);
	//ȷ��Ԫ��theElement�Ƿ��ҵ�
	if (theIndex == listSize)
		//������û�ҵ�
		return -1;
	else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{//ɾ����������Ԫ��
 //��û�и�Ԫ�أ����׳��쳣
	checkIndex(theIndex);
	//������Ч
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();  //Ҫ��������һ��Ԫ�أ�Ԫ�ظ�����һ
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{//������theIndex������Ԫ��theElement
 //�����������ڣ����׳��쳣
	checkIndex(theIndex);
	//��Ч���������ж������Ƿ�����
	if (full())
	{
		ChangeArrayLength(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	//copy_backward(b,e,d):����b,e����Χ�ڵ�Ԫ�أ����Ƶ���dΪ�յ���λ��
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{//�����Ա�����������
	copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}
#endif // !ARRAYLIST_H

