/*
 * W2MoveStrings.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 */

#include <string>
#include <vector>

using namespace std;

void MoveStrings(
		vector<string>& source, vector<string>& destination){
	for (auto i: source){
		destination.push_back(i);
	}
	source.clear();
}

