// Binary Search Tree.cpp : Defines the entry point for the console application.
//
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h >
#include <crtdbg.h >
#include "stdafx.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  cout << "Hello Binary Search Tree" << endl;
	/* BinarySearchTree bt (); is NO good */
	{
		BinarySearchTree<int> bst;
		bst.insert(3); 
		bst.insert(20);
		bst.insert(15);
		bst.insert(77);
		bst.insert(9);
		cout << "Debugging..." << endl;
	}
	//_CrtSetBreakAlloc(222);
	
	cout << "Debugging..." << endl;
	_CrtDumpMemoryLeaks();
	return 0;
}

