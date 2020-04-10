/*
 * W2UniqStrings.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 *
 * Task:
 * https://www.coursera.org/learn/c-plus-plus-white/programming/7rcDW/kolichiestvo-unikal-nykh-strok
 */

#include <iostream>
#include <set>
using namespace std;

void UniqStrings(){
	int n;
	string s;
	set<string> uniq_strings;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> s;
		uniq_strings.insert(s);
	}
	cout << uniq_strings.size() << endl;
}
