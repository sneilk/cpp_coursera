/*
 * W2Capitals.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/ZUCo1/spravochnik-stolits
 */

#include <iostream>
#include <map>
using namespace std;

void About(map<string, string>& capitals){
	string country;
	cin >> country;
	if (capitals.count(country)){
		cout << "Country " << country << " has capital " << capitals[country] << endl;
	} else {
		cout << "Country " << country << " doesn't exist" << endl;
	}
}


void ChangeCapital(map<string, string>& capitals){
	string country, new_capital;

	cin >> country >> new_capital;
	if (!capitals.count(country)){
		capitals[country] = new_capital;
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	} else if (capitals[country] == new_capital){
		cout << "Country " << country << " hasn't changed its capital" << endl;
	} else {
		cout << "Country " << country << " has changed its capital from ";
		cout << capitals[country] << " to " << new_capital << endl;
		capitals[country] = new_capital;
	}
}


void Dump(const map<string, string>& capitals){
	if (capitals.size()){
		for (const auto& [key, value]: capitals){
			cout << key << "/" << value << " ";
		}
		cout << endl;
	} else {
		cout << "There are no countries in the world" << endl;
	}
}


void Rename(map<string, string>& capitals){
	string old_country, new_country;

	cin >> old_country >> new_country;
	if (!capitals.count(new_country) && capitals.count(old_country) && old_country != new_country){
		capitals[new_country] = capitals[old_country];
		capitals.erase(old_country);
		cout << "Country " << old_country << " with capital " << capitals[new_country];
		cout << " has been renamed to " << new_country << endl;
	} else {
		cout << "Incorrect rename, skip" << endl;
	}
}


void Capitals(){
	int n;
	string query;
	map<string, string> capitals;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> query;

		if (query == "CHANGE_CAPITAL"){
			ChangeCapital(capitals);
		} else if (query == "RENAME") {
			Rename(capitals);
		} else if (query == "ABOUT") {
			About(capitals);
		} else if (query == "DUMP") {
			Dump(capitals);
		}
	}
}

