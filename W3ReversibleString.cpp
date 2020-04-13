/*
 * W3ReversibleString.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/zzTXi/stroka
 */

#include <algorithm>
#include <string>
using namespace std;
class ReversibleString {
public:
	ReversibleString(){}

	ReversibleString(const string& s){
		rev_string = s;
	}

	void Reverse(){
		reverse(begin(rev_string), end(rev_string));
	}

	string ToString() const{
		return rev_string;
	}

private:
	string rev_string;
};

