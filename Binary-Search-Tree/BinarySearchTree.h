#pragma once
#include "TreeNode.h"

template <class T>
class BinarySearchTree
{
private:
  tree_node<T> *root;
public:
	BinarySearchTree(void);
	bool isEmpty();
	void insert(T);
	void levelOrder();
	~BinarySearchTree(void);
	void deleteNodes(tree_node<T> *);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(void)
{
	this->root = NULL;	
}

template <class T>
bool BinarySearchTree<T>::isEmpty() {
	return (this->root == NULL);
}

template <class T>
void BinarySearchTree<T>::insert(T data) {
	tree_node<T> *new_node = new tree_node<T>;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	if (this->isEmpty()) {
		root = new_node;
		return;
	}

	tree_node<T> *parent;
	tree_node<T> *parent_runner = root;
	while (parent_runner != NULL) {
		parent = parent_runner;
		if (new_node->data < parent_runner->data)
			parent_runner = parent_runner->left;
		else
			parent_runner = parent_runner->right;
	}

	if (new_node->data < parent->data)
		parent->left = new_node;
	else
		parent->right = new_node;


	
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree(void)
{
	this->deleteNodes(this->root);
}

template <class T>
void BinarySearchTree<T>::deleteNodes(tree_node<T> *node) {
	if (node == NULL)
		return;

	if (node->left != NULL)
		this->deleteNodes(node->left);

	if (node->right != NULL)
		this->deleteNodes(node->right);

	delete node;
}

