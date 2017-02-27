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

/*arrayList*/
//linearList
template<class T>
class arrayList :public linearList<T>
{
public:
	/**arrayList constructor ,copy constructor, destructor**/
	//constructor
	arrayList(int initialCapacity = 10);
	//copy cosntructor
	arrayList(const arrayList<T>&);
	//destructor
	~arrayList() { delete[] element; }

	/**ADT abstract data type**/
	//if the linear list is empty, return ture,else return false
	bool empty() const { return listSize == 0; }
	//if the linear list is full ,return ture,else return false
	bool full() const { return listSize == arrayLength; }
	//get the size of the linear list and return it
	int size() const { return listSize; }
	//get the value in the index of the array at theIndex
	T& get(int theIndex) const;
	//get the index of value "theElement" in the array
	int indexOf(const T& theElement) const;
	//erase the value in the array at the theIndex
	void erase(int theIndex);
	//insert theElement into the array at the theIndex
	void insert(int theIndex, const T& theElement);
	//output the list
	void output(ostream& out) const;
	//return the capacity of the array
	int capacity() const { return arrayLength; }

private:
	//check if the index is valid, if it`s unvalid ,throw an exception
	void checkIndex(int theIndex) const;	
	//list member
	T* element;
	//list total capacity
	int arrayLength;
	//list length
	int listSize;			
};

//change the array length definition
template<class Tc>
void ChangeArrayLength(Tc*& str, int OldLength, int NewLength);

//
template<class Tc>
void ChangeArrayLength(Tc*& str, int OldLength, int NewLength)  
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
{//check if the initial capacity is valid
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

//copy constructor definition
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
{//the index should be among 0 ~ listsize-1
	if (theIndex < 0 || theIndex > listSize-1)
	{
		//ostringstream s;
		cout << "index = " << theIndex << " size = " << listSize;
		exit(-1);
		//throw s;
	}
}


template<class T>
T& arrayList<T>::get(int theIndex) const
{
	//check if the index is valid
	checkIndex(theIndex);
	//index is valid
	return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
 //return the index where theElement first occurs
	int theIndex = (int)(find(element, element + listSize, theElement) - element);

	if (theIndex == listSize)
		return -1;
	else return theIndex;
}

template<class T>
void arrayList<T>::erase(int theIndex)
{//delete the element whose index is theIndex
	checkIndex(theIndex);
	//index is valid
	copy(element + theIndex + 1, element + listSize, element + theIndex);
	element[--listSize].~T();  //expilicit call the destructor
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{//insert the theElement into the array at index theIndex

	checkIndex(theIndex);
	//index is valid , check if the array is full,if the array is full , double the capacity of the array
	if (full())
	{
		ChangeArrayLength(element, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	//copy_backward(b,e,d):copy the element among e to b from e to d
	//exp: str[100]="abcd",copy_backwar(str,str+1,str+3) ==> str[100]="abab"           
	copy_backward(element + theIndex, element + listSize, element + listSize + 1);
	element[theIndex] = theElement;
	listSize++;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{
	copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}
#endif // !ARRAYLIST_H

