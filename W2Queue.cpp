/*
 * W2Queue.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Queue(){

	int n, k;
	string s;
	cin >> n;

	vector<bool> v;
	for (int i =0; i < n; ++i){
		cin >> s;
		if (s == "COME") {
			cin >> k;
			v.resize(v.size() + k);
		} else if (s == "WORRY") {
			cin >> k;
			v[k] = true;
		} else if (s == "QUIET") {
			cin >> k;
			v[k] = false;
		}
		else if (s == "WORRY_COUNT"){
			int sum = 0;
			for (int i: v){
				if (i){
					sum += 1;
				}
			}
			cout << sum<< endl;
		}
	}

}

