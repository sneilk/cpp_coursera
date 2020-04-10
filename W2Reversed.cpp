/*
 * W2Reversed.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 */

#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v){
	vector<int> result;
	for (int i = v.size() - 1; i >= 0; --i){
		result.push_back(v[i]);
	}
	return result;
}

