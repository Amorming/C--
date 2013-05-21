// Two Sum.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main(int argc, char *arg[]) {
  int array[] = {2, 7, 11, 15};
	int target = 9;
	vector<int> numbers (array, array + sizeof(array) / sizeof(int));
	vector<int> answer;
	answer = twoSum(numbers, target);
	cout << answer[0] << " " << answer[1] << endl;
}

vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> ret (2, 0);
	unordered_map<int, int> map;
	unordered_map<int, int>::iterator itr;
	for (int i = 0; i < numbers.size(); i++) {
		itr = map.find(numbers[i]);
		if (itr == map.end())
			map.insert(pair<int, int>((target - numbers[i]), i));
		else {
			ret[0] = itr->second + 1;
			ret[1] = i + 1;
			break;
		}
	}
	
	return ret;
}
