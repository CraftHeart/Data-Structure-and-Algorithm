#pragma once
//chain node

#ifndef CHAINNODE_H_
#define CHAINNODE_H_

/*定义一个节点的数据类型*/
template<class T>
class chainNode
{
	//数据成员
public:
	T element;
	chainNode<T>* next;
	//方法
public:
	chainNode() {}
	chainNode(const T& element) : element{ element } {}
	chainNode(const T& element, chainNode<T>* next) :element{ element }, next{ next } {}
};

#endif // !CHAINNODE_H_
