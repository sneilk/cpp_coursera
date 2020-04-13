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

void ReadFileII(){
	string name_input = "input.txt";
	string name_output = "output.txt";
	ifstream input(name_input);
	ofstream output(name_output);
	string result;

	if (input) {
		while (getline(input, result)) {
			output << result << endl;
		}
	}
}

