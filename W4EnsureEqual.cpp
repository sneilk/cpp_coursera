/*
 * W4EnsureEqual.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/jNmrf/funktsiia-ensureequal
 */

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void EnsureEqual(const string& left, const string& right){
	string s;
	s = left + " != " + right;
	if (left != right){
		throw runtime_error(s);
	}
}

