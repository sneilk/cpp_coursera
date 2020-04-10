/*
 * W2Anagramns.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 */

#include <iostream>
#include <map>
using namespace std;

bool IsAnagramm(const string& s1, const string& s2){

	map<char, int> v1, v2;
	for (const auto& i : s1){
		++v1[i];
	}

	for (const auto& i : s2){
		++v2[i];
	}

	return v1 == v2;
}


void Anagramms(){
	int n;
	string s1, s2, answer;

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> s1 >> s2;
		if (IsAnagramm(s1, s2)){
			answer = "YES";
		} else {
			answer = "NO";
		}
		cout << answer << endl;
	}
}



