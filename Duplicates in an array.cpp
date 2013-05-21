// Duplicates in an array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
/* must pass the length of array explicitly */
unordered_set<int> get_dup_set(int array[], int len);
vector<int> get_dup_naive(int *array, int len);
vector<int> get_dup_sort(int *array, int len);

void main()
{
  /* answer would be 2, 3, 1 ,4, 8 */
	int array[] = {1, 8, 2, 3, 4, 2, 3, 1 ,1 ,3 ,4 ,5 ,6 ,8, 8, 9, 23};
	int len = sizeof(array) / sizeof(int);
	unordered_set<int> dup_set = get_dup_set(array, len);

	/* iterate through the set */
	unordered_set<int>::iterator itr = dup_set.begin();
	while (itr != dup_set.end()) {
		cout << *itr << " ";
		itr++;
	}
	cout << endl;

	vector<int> dup_vector = get_dup_naive(array, len);
	for (int i = 0; i < dup_vector.size(); i++) {
		cout << dup_vector[i] << " ";
	}
	cout << endl;

	vector<int> dup_sort = get_dup_sort(array, len);
	for (int i = 0; i < dup_sort.size(); i++) {
		cout << dup_sort[i] << " ";
	}
	cout << endl;
}

unordered_set<int> get_dup_set(int array[], int len) {
	unordered_set<int> dup_set;
	unordered_set<int> uni_set;

	for (int i = 0; i < len; i++) {
		if (uni_set.find(array[i]) == uni_set.end())
			uni_set.insert(array[i]);
		else
			dup_set.insert(array[i]);
	}

	return dup_set;
}

vector<int> get_dup_naive(int *array, int len) {
	vector<int> ret;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			/* i != j is important */
			if (array[i] == array[j]) {
				ret.push_back(array[i]);
				/* don't check further */
				break;
			}
		}
	}
	return ret;
}

vector<int> get_dup_sort(int *array, int len) {
	int *end = array + len;
	sort(array, end);
	vector<int> ret;
	if (len < 2)
		return ret;

	int checker = array[0];
	for (int i = 1; i < len; i++) {
		if (array[i] == checker) {
			ret.push_back(checker);
			while (i < len && array[i] == checker)
				i++;
			if (i == len)
				return ret;
			else
				checker = array[i];
		}
		else
			checker = array[i];
	}

	return ret;
}

