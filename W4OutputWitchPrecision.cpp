/*
 * W4OutputWitchPrecision.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/ndSVY/vyvod-s-tochnost-iu
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void OutputWithPrecision(){
	string file = "input.txt";
	ifstream input(file);
	string number;

	cout << fixed << setprecision(3);
	if (input) {
		while (getline(input, number)) {
			cout << stod(number) << endl;
		}
	}
}

