/*
 * W2Reverse.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 */
#include <vector>
using namespace std;

void Reverse(vector<int>& v){
	for (int i = 0; i< v.size() / 2; ++i){
		int tmp = v[i];
		v[i] = v[v.size() - 1 - i];
		v[v.size() - 1 - i] = tmp;
	}
}
