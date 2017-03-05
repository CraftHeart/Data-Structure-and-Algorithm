#pragma once
#ifndef  TREE_NODE_H_
#define TREE_NODE_H_

template<class T>
class TreeNode
{
public:
	TreeNode()
	{
		left_child_ = nullptr;
		right_child_ = nullptr;
	}
	TreeNode(const T& the_element) :element_{the_element}
	{
		left_child_ = nullptr;
		right_child_ = nullptr;
	}
	TreeNode(const T& the_element, TreeNode<T>* left_child, TreeNode<T>* right_child)
	{
		element_ = the_element;
		left_child_ = left_child;
		right_child_ = right_child;
	}
public:
	T element_;   //节点元素
	TreeNode<T>* left_child_; //左孩子节点
	TreeNode<T>* right_child_; //右孩子节点
};
#endif // ! TREE_NODE_H_
