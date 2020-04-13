/*
 * W4ReadAndOutTable.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/uyK0H/chtieniie-i-vyvod-tablitsy
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintStr(const string& s){
	cout << setw(10) << s;
}

void ReadAndOutTable(){
	string name = "input.txt";
	ifstream input(name);
	string s;
	int n, m;

	if (input) {
		getline(input, s, ' ');
		n = stoi(s);
		getline(input, s);
		m = stoi(s);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m-1; ++j){
				getline(input, s, ',');
				PrintStr(s);
				cout << " ";
			}
			getline(input, s);
			PrintStr(s);
			if (i < n-1) {
				cout << "\n";
			}
		}
	}
}


