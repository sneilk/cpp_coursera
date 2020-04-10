/*
 * W2MonthlyDeals.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Add(vector<vector<string>>& d){
	int n;
	string s;

	cin >> n >> s;
	if (n <= d.size()){
		d[n-1].push_back(s);
	}
}

void Dump(vector<vector<string>>& d){
	int n;
	cin >> n;

	if (n <= d.size()) {
		cout << d[n-1].size() << " ";
		for (auto i: d[n-1]){
			cout << i << " ";
		}
		cout << endl;
	}
}

void Next(vector<vector<string>>& d, int n){
	for (int i = n; i < d.size(); ++i){
			d[n-1].insert(end(d[n-1]), begin(d[i]), end(d[i]));
	}
	d.resize(n);
}


void MonthlyDeals(){
	int n;
	int month = 0;
	string command;
	vector<int> months = {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> deals(months[month]);

	cin >> n;

	for (int i=0; i < n; ++i){
		cin >> command;
		if (command == "ADD"){
			Add(deals);
		} else if (command == "NEXT") {
			month += 1;
			Next(deals, months[month % 12]);
		} else if (command == "DUMP") {
			Dump(deals);
		}
	}
}

