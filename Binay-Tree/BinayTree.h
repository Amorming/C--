#pragma once

#include "TreeNode.h"

class BinaryTree
{
public:

  BinaryTree(void);
	BinaryTree(tree_node *root);
	bool isEmpty();
	~BinaryTree(void);

private:
	tree_node *root;
	/* a member with an in-class initializer must be const */
	static const int LEFT= -1;
	static const int RIGHT = 1;
};

