/*
 * W2Synonymous.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/WRbZE/sinonimy
 */

#include <iostream>
#include <map>
#include <set>
using namespace std;

void CountWords(map<string, set<string>>& s){
	string s1;

	cin >> s1;
	cout << s[s1].size() << endl;
}


void Check(map<string, set<string>>& s){
	string s1, s2;

	cin >> s1 >> s2;
	if (s[s1].count(s2)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}


void Add(map<string, set<string>>& s){
	string s1, s2;

	cin >> s1 >> s2;
	s[s1].insert(s2);
	s[s2].insert(s1);
}


void Synonyms(){
	unsigned int n;
	string s;
	map<string, set<string>> synonyms_dict;

	cin >> n;
	for (int i =0; i < n; ++i) {
		cin >> s;
		if (s == "ADD"){
			Add(synonyms_dict);
		} else if(s == "COUNT") {
			CountWords(synonyms_dict);
		} else if(s == "CHECK"){
			Check(synonyms_dict);
		}
	}
}

