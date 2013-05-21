#include "BinaryTree.h"
#include <stdlib.h>


BinaryTree::BinaryTree(void)
{
  this->root = NULL;
}

BinaryTree::BinaryTree(tree_node *root) {
	this->root = root;
}

bool BinaryTree::isEmpty() {
	return (this->root == NULL);
}

BinaryTree::~BinaryTree(void)
{
}
