#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"
using namespace std;

void main() {
  cout << "Hello Binary Tree" << endl;
	tree_node *three = new tree_node (3);
	tree_node *nine = new tree_node (9);
	tree_node *twenty = new tree_node (20);
	tree_node *fifteen = new tree_node (15);
	tree_node *seven = new tree_node (7);
	
	three->left = nine;
	three->right = twenty;
	twenty->left = fifteen;
	twenty->right = seven;

	BinaryTree bt (three);

	int i;
	cin >> i;
	if (i == 1)
		exit(0);
}
