//数据结构测试Main程序
#include"arrayList.h"
#include"chain.h"
#include<iostream>
#include"SinglyLinkedCircularList.h"
#include"doubly_linked_list.h"
#include"circle_doubly_linked_list.h"
#include"queue.h"

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
	/*my_list.erase(3);
	cout << "my_list[3]=" << my_list[3] << endl;*/

	DoublyLinkedList<int> my_list2(my_list);
	cout << "after copy constructor my_list2[3]=" << my_list2[3] << endl;
	my_list2.erase(3);
	cout << "after erase my_list2[3]=" << my_list2[3] << endl;

	my_list = my_list2;
	cout << "after copy assignmenet my_list[3]=" << my_list[3] << endl;
}

void test_circle_doubly_linked_list()
{
	CircleDoublyLinkedList<int> list1;
	for (int i = 0; i < 10; i++)
		list1.insert(i, i);
	cout << "list1[3]= " << list1[3] << endl;
	list1.insert(3, 102);
	cout << "list1[3]= " << list1[3] << endl;
	cout << "list1[4]= " << list1[4] << endl;
	list1.erase(4);
	cout << "list1[4]= " << list1[4] << endl;
	CircleDoublyLinkedList<int> list2(list1);
	list1.insert(3, 11);
	cout << "list1[3]= " << list1[3] << endl;
	list2 = list1;
	cout << "list2[3]= " << list2[3] << endl;
}

void test_queue()
{
	ArrayQueue<int> arrayqueue;
	for (int i = 0; i < 10; i++)
	{
		arrayqueue.push(i);
	}
	cout << "arrayqueue size " << arrayqueue.size() << endl;
	cout << "arrayqueue front = " << arrayqueue.front() << endl;
	cout << "arrayqueue back = " << arrayqueue.back() << endl;
	arrayqueue.pop();
	cout << "after pop arrayqueue front = " << arrayqueue.front() << endl;
	cout << "after pop arrayqueue size " << arrayqueue.size() << endl;

	ListQueue<int> list_queue;
	for (int i = 0; i < 10; i++)
	{
		list_queue.push(i);
	}
	cout << "list queue size = " << list_queue.size() << endl;
	cout << "list queue front = " << list_queue.front() << endl;
	cout << "list queue back = " << list_queue.back() << endl;
	list_queue.pop();
	cout << "after pop list queue size = " << list_queue.size() << endl;
	cout << "after pop list queue front = " << list_queue.front() << endl;

}

int main()
{
	//test_doubly_linked_list();
	//test_circle_doubly_linked_list();
	test_queue();
	return 0;
}