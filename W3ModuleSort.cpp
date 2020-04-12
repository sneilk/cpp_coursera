/*
 * W3ModuleSort.cpp
 *
 *  Created on: Apr 12, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/D5IKE/sortirovka-tsielykh-chisiel-po-moduliu
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool ModuleCompare(int i, int j){
	return (abs(i) < abs(j));
}

void ModuleSort(){
	vector<int> v;

	int n, k;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> k;
		v.push_back(k);
	}

	sort(begin(v), end(v), ModuleCompare);

	for (const auto& i : v){
		cout << i <<  " ";
	}
}
