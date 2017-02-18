//数据结构测试Main程序
#include"arrayList.h"
#include"chain.h"
#include<iostream>
#include"SinglyLinkedCircularList.h"
#include"doubly_linked_list.h"

using namespace std;

void test_arraylist()
{
	arrayList<int> myarray(100);
	cout << myarray.capacity() << endl;
	for (int i = 0; i < 11; )
	{
		myarray.insert(i, i);
		i++;
	}
	cout << myarray.get(10) << endl;
}

void test_chain()
{
	chain<int> mychain;
	for (int i = 0; i < 10; i++)
	{
		mychain.insert(i, i);
	}
	cout << "mychain.get(2)=" << mychain.get(2) << endl;
	mychain.erase(2);
	cout << "mychain.get(2)=" << mychain.get(2) << endl;
}

void test_SinglyLinkedCircularList()
{
	SinglyLinkedCircularList<int> my_list;
	for (int i = 0; i < 10; i++)
	{
		my_list.Insert(i, i);
	}
	cout << "my_list[7]=" << my_list.get(7) << endl;
	my_list.erase(7);
	cout << "my_list[7]=" << my_list.get(7) << endl;
}

void test_doubly_linked_list()
{
	DoublyLinkedList<int> my_list;
	for (int i = 0; i < 10; i++)
	{
		my_list.insert(i, i);
	}
	cout << "my_list[3]=" << my_list[3] << endl;
	my_list.insert(3, 10);
	cout << "my_list[3]=" << my_list[3] << endl;
	my_list.erase(3);
	cout << "my_list[3]=" << my_list[3] << endl;
}

int main()
{
	test_doubly_linked_list();
	return 0;
}