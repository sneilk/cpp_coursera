/*
 * W4ReversedFunction.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/8O6Xb/obratimaia-funktsiia
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FunctionPart{
public:
	FunctionPart(char new_operation, double new_value){
		operation = new_operation;
		value = new_value;
	}

	double Apply(double source_val) const {
		if (operation == '+') {
			return source_val + value;
		} else  if (operation == '-'){
			return source_val - value;
		} else  if (operation == '*'){
			return source_val * value;
		} else  if (operation == '/'){
			return source_val / value;
		}
	}

	void Invert(){
		if (operation == '+'){
			operation= '-';
		} else  if (operation == '-'){
			operation = '+';
		} else  if (operation == '*'){
			operation = '/';
		} else  if (operation == '/'){
			operation = '*';
		}
	}

private:
	char operation;
	double value;
};


class Function {
public:
	void AddPart(char op, double value){
		parts.push_back({op, value});
	}

	double Apply(double value) const{
		for (const FunctionPart& part : parts){
			value = part.Apply(value);
		}
		return value;
	}

	void Invert(){
		for (FunctionPart& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}

private:
	vector<FunctionPart> parts;
};
