/*
 * W4WorkWithFiles.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/NZTXy/rabota-s-failami
 */


#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void ReadFile(){
	string name = "input.txt";
	ifstream input(name);
	string result;

	if (input) {
		while (getline(input, result)) {
			cout << result << endl;
		}
	}

}
