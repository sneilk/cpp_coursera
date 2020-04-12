/*
 * W3StringSort.cpp
 *
 *  Created on: Apr 12, 2020
 *      Author: sneilk
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool StrCompare(string s1, string s2){
	for (auto& i : s1){
		i = ::tolower(i);
	}
	for (auto& i : s2){
		i = ::tolower(i);
	}
	return (s1 < s2);
}

int IntInput(){
	int i;
	cin >> i;
	return i;
}

string StrInput(){
	string s;
	cin >> s;
	return s;
}

void StringSort(){
	int n = IntInput();
	vector<string> str_vect;

	for (int i = 0; i < n; ++i){
		str_vect.push_back(StrInput());
	}
	sort(begin(str_vect), end(str_vect), StrCompare);
	for (const auto& i : str_vect) {
		cout << i << " ";
	}
}

