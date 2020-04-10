/*
 * W2BuildMapValueSet.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/DULBh/mnozhiestvo-znachienii-slovaria
 */

#include <map>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m){
	set<string> result;

	for (const auto& [key, value] : m){
		result.insert(value);
	}
	return result;
}

