#pragma once
#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include<iostream>
#include<deque>
#include<stack>
#include"tree_node.h"

using namespace std;

//binary tree ADT
template<class T>
class BinaryTree
{
public:
	virtual ~BinaryTree() {}
	virtual bool empty() const;//��������Ϊ�գ��򷵻�ture
	virtual int size() const ;//���ض�������Ԫ�ظ������ڵ������

	virtual void recursion_preorder(TreeNode<T>*) const ;//�ݹ��������
	virtual void recursion_inorder(TreeNode<T>*)const ;//�ݹ��������
	virtual void recursion_postorder(TreeNode<T>*)const ;//�ݹ�������

	virtual void level_order(TreeNode<T>*)const ;//��α���

	virtual void nonrecursion_preorder(TreeNode<T>*) const ;//�ǵݹ��������
	virtual void nonrecursion_inorder(TreeNode<T>*)const ;//�ǵݹ��������
	virtual void nonrecursion_postorder(TreeNode<T>*)const ;//�ǵݹ�������
};

template<class T>
class LinkedBinaryTree
{
public:
	LinkedBinaryTree()
	{
		root_ = nullptr;
		tree_size_ = 0;
	}
	LinkedBinaryTree(const LinkedBinaryTree<T>&);

	~LinkedBinaryTree();

	bool empty() const { return tree_size_==0; }

	int size() const { return tree_size_; }

	void make_tree(const T &the_element, LinkedBinaryTree<T>& left_tree, LinkedBinaryTree<T>& right_tree);

	bool compare(const LinkedBinaryTree<T>&);//�Ƚ�����������ͬ�򷵻�ture

	void swap_tree();//����ÿһ���ڵ����������

	void recursion_preorder() const//�ݹ��������
	{
		recursion_preorder(root_);
	}
	void recursion_inorder() const//�ݹ��������
	{
		recursion_inorder(root_);
	}
	void recursion_postorder() const//�ݹ�������
	{
		recursion_postorder(root_);
	}

	void level_order() const//��α���
	{
		level_order(root_);
	}

	void nonrecursion_preorder() const//�ǵݹ��������
	{
		nonrecursion_preorder(root_);
	}
	void nonrecursion_inorder() const//�ǵݹ��������
	{
		nonrecursion_inorder(root_);
	}
	void nonrecursion_postorder() const//�ǵݹ�������
	{
		nonrecursion_postorder(root_);
	}

	int height() const //�������ĸ߶�
	{
		return tree_height(root_);
	}
	void erase(); //ɾ���������нڵ�
	void dispose(TreeNode<T>* tree_node); //ɾ������ĳһ���ڵ�

public:
	static void recursion_preorder(TreeNode<T>* tree) ;//�ݹ��������
	static void recursion_inorder(TreeNode<T>* tree) ;//�ݹ��������
	static void recursion_postorder(TreeNode<T>* tree) ;//�ݹ�������

	static void level_order(TreeNode<T>* tree) ;//��α���

	static void nonrecursion_preorder(TreeNode<T>* tree) ;//�ǵݹ��������
	static void nonrecursion_inorder(TreeNode<T>* tree) ;//�ǵݹ��������
	static void nonrecursion_postorder(TreeNode<T>* tree) ;//�ǵݹ�������

	static int tree_height(TreeNode<T>* tree) ; //�������ĸ߶�

	static void swap_tree(TreeNode<T>* tree);//�����ڵ����������

	static bool compare(TreeNode<T>* tree_node1, TreeNode<T>* tree_node2);//�Ƚ������ڵ��Ƿ���ͬ

	static TreeNode<T>* copy(TreeNode<T>*);//����һ���ڵ�

private:
	static void visit(TreeNode<T>* tree_node);//����ĳ���ڵ�Ԫ��
	TreeNode<T>* root_;//���ڵ�
	int tree_size_;//���Ĵ�С
};

template<class T>
void LinkedBinaryTree<T>::visit(TreeNode<T>* tree_node)
{
	cout << tree_node->element_ << ' ';
}

template<class T>
TreeNode<T>* LinkedBinaryTree<T>::copy(TreeNode<T>* tree_node)
{
	if (tree_node == nullptr)
		return nullptr;
	TreeNode<T>* temp = new TreeNode<T>(tree_node->element_);
	temp->left_child_ = copy(tree_node->left_child_);
	temp->right_child_ = copy(tree_node->right_child_);
	return temp;
}

template<class T>
void LinkedBinaryTree<T>::swap_tree(TreeNode<T>* tree)
{
	if (tree != nullptr)
	{
		TreeNode<T>* temp_node = tree->left_child_;
		tree->left_child_ = tree->right_child_;
		tree->right_child_ = temp_node;

		swap_tree(tree->left_child_);
		swap_tree(tree->right_child_);
	}
}

template<class T>
LinkedBinaryTree<T>::LinkedBinaryTree(const LinkedBinaryTree& tree)
{//�������ĸ��ƹ��캯��
	root_ = copy(tree.root_);
}


template<class T>
bool LinkedBinaryTree<T>::compare(TreeNode<T>* tree_node1, TreeNode<T>* tree_node2)
{
	if (tree_node1 == nullptr&&tree_node2 == nullptr)
		return true;

	if (((tree_node1 != nullptr) && (tree_node2 == nullptr)) || ((tree_node1 == nullptr) && (tree_node1 != nullptr)))
		return false;
	if (tree_node1->element_ != tree_node2->element_)
		return false;

	bool left = compare(tree_node1->left_child_, tree_node2->left_child_);
	bool right = compare(tree_node1->right_child_, tree_node2->right_child_);

	return (left&&right);
}

template<class T>
bool LinkedBinaryTree<T>::compare(const LinkedBinaryTree<T>& tree)
{//�Ƚ�����������ͬ�򷵻�ture
	return compare(root_, tree.root_);
}

template<class T>
void LinkedBinaryTree<T>::swap_tree()
{//����ÿһ���ڵ����������
	swap_tree(root_);
}

template<class T>
LinkedBinaryTree<T>::~LinkedBinaryTree()
{
	erase();
	root_ = nullptr;
	tree_size_ = 0;
}

template<class T>
void LinkedBinaryTree<T>::make_tree(const T &the_element, LinkedBinaryTree<T>& left_tree, LinkedBinaryTree<T>& right_tree)
{
	root_ = new TreeNode<T>(the_element, left_tree.root_, right_tree.root_);
	tree_size_ = left_tree.tree_size_ + right_tree.tree_size_ + 1;
}

template<class T>
void LinkedBinaryTree<T>::recursion_preorder(TreeNode<T>* tree) 
{
	if (tree != nullptr)
	{
		visit(tree);
		recursion_preorder(tree->left_child_);
		recursion_preorder(tree->right_child_);
	}
}

template<class T>
void LinkedBinaryTree<T>::recursion_inorder(TreeNode<T>* tree) 
{
	if (tree != nullptr)
	{
		recursion_inorder(tree->left_child_);
		visit(tree);
		recursion_inorder(tree->right_child_);
	}
}

template<class T>
void LinkedBinaryTree<T>::recursion_postorder(TreeNode<T>* tree) 
{
	if (tree != nullptr)
	{
		recursion_postorder(tree->left_child_);
		recursion_postorder(tree->right_child_);
		visit(tree);
	}
}

template<class T>
void LinkedBinaryTree<T>::level_order(TreeNode<T>* tree) 
{//use deque
	if (tree == nullptr)
	{
		cerr << "level_order error : tree is empty" << endl;
		exit(-1);
	}

	deque<TreeNode<T>*> queue;
	TreeNode<T>* current_node = tree;
	while (current_node != nullptr)
	{
		visit(current_node);

		if (current_node->left_child_ != nullptr)
			queue.push_back(current_node->left_child_);
		if (current_node->right_child_ != nullptr)
			queue.push_back(current_node->right_child_);
		if (!queue.empty())
		{
			current_node = queue.front();
			queue.pop_front();
		}
		else
		{
			current_node = nullptr;
		}
	}
}

template<class T>
void LinkedBinaryTree<T>::nonrecursion_preorder(TreeNode<T>* tree) 
{//use stack
	if (tree == nullptr)
	{
		cerr << "nonrecursion_preorder error : tree is empty" << endl;
		exit(-1);
	}
	stack<TreeNode<T>*> tree_stack;
	TreeNode<T>* current_node = tree;
	//while (current_node != nullptr)
	//{
	//	visit(current_node);
	//	if (current_node->right_child_ != nullptr)
	//		tree_stack.push(current_node->right_child_);
	//	if (current_node->left_child_ != nullptr)
	//		tree_stack.push(current_node->left_child_);

	//	current_node = tree_stack.top();
	//	tree_stack.pop();
	//}
	while (current_node != nullptr || !tree_stack.empty())
	{
		while (current_node != nullptr)
		{
			tree_stack.push(current_node);
			visit(current_node);
			current_node = current_node->left_child_;
		}
		if (!tree_stack.empty())
		{
			current_node = tree_stack.top();
			current_node = current_node->right_child_;
			tree_stack.pop();
		}
	}
}

template<class T>
void LinkedBinaryTree<T>::nonrecursion_inorder(TreeNode<T>* tree) 
{
	if (tree == nullptr)
	{
		cerr << "nonrecursion_inorder error : tree is empty" << endl;
		exit(-1);
	}
	stack<TreeNode<T>*> tree_stack;
	TreeNode<T>* current_node = tree;
	while (current_node != nullptr||!tree_stack.empty())
	{
		while (current_node != nullptr)
		{
			tree_stack.push(current_node);
			current_node = current_node->left_child_;
		}
		if (!tree_stack.empty())
		{
			current_node = tree_stack.top();
			visit(current_node);
			current_node = current_node->right_child_;
			tree_stack.pop();
		}
	}
}

template<class T>
void LinkedBinaryTree<T>::nonrecursion_postorder(TreeNode<T>* tree) 
{
	if (tree == nullptr)
	{
		cerr << "nonrecursion_postorder error : tree is empty" << endl;
		exit(-1);
	}
	stack<TreeNode<T>*> tree_stack;
	TreeNode<T>* current_node = tree;
	TreeNode<T>* last_visit_node = nullptr;

	tree_stack.push(current_node);
	while (!tree_stack.empty())
	{
		current_node = tree_stack.top();
		if ((current_node->right_child_ == nullptr) && (current_node->left_child_ == nullptr)
			|| ((current_node != nullptr) && (last_visit_node == current_node->left_child_ || last_visit_node == current_node->right_child_)))
		{
			visit(current_node);
			last_visit_node = current_node;
			tree_stack.pop();
		}
		else
		{
			if (current_node->right_child_ != nullptr)
				tree_stack.push(current_node->right_child_);
			if (current_node->left_child_ != nullptr)
				tree_stack.push(current_node->left_child_);
		}
	}
}

template<class T>
int LinkedBinaryTree<T>::tree_height(TreeNode<T>* tree) 
{
	if (tree == nullptr)
		return 0;
	int hl = tree_height(tree->left_child_);
	int hr = tree_height(tree->right_child_);
	if (hl > hr)
		return ++hl;
	else
		return ++hr;
}

template<class T>
void LinkedBinaryTree<T>::erase()
{

}

template<class T>
void LinkedBinaryTree<T>::dispose(TreeNode<T>* tree_node)
{

}

void find_postorder(const char* preorder, const char* inorder,int len)
{
	if (len == 0)
		return;
	char root = preorder[0];
	int inorder_root_index = -1;
	while (root != inorder[++inorder_root_index]);

	find_postorder(preorder + 1, inorder, inorder_root_index);
	find_postorder(preorder + inorder_root_index + 1, inorder + inorder_root_index + 1, len - inorder_root_index - 1);
	cout << root ;
}

void find_preorder(const char* postorder, const char* inorder, int len)
{
	if (len == 0)
		return;
	char root = postorder[len - 1];
	int inorder_root_index = -1;
	while (root != inorder[++inorder_root_index]);

	cout << root;
	find_preorder(postorder, inorder, inorder_root_index);
	find_preorder(postorder+inorder_root_index, inorder + inorder_root_index + 1, len - inorder_root_index - 1);
}


#endif // !BINARY_TREE_H_

