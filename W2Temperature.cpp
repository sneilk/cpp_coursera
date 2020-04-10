/*
 * W2Temperature.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 */

#include <iostream>
#include <vector>
using namespace std;

double Mean(const vector<int>& v){
	int sum = 0;
	for (auto i: v){
		sum += i;
	}

	return sum / v.size();
}

void Temperature(){
	int n;
	cin >> n;

	vector<int> temp(n);
	vector<int> high_mean_temp;

	for (int& t: temp){
		cin >> t;
	}

	double mean_temp = Mean(temp);
	for (int i = 0; i < n; ++i){
		if (temp[i] > mean_temp){
			high_mean_temp.push_back(i);
		}
	}

	int vsize = high_mean_temp.size();
	cout << vsize << endl;
	for (int i = 0; i < vsize; ++i){
		cout << high_mean_temp[i] << " ";
	}
}
