/*
 * W2BusStops2.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/1mOPD/avtobusnyie-ostanovki-2
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;


void BusStopII(){
	int n, m;
	map<vector<string>, int> bus_routes;
	string bus_stop;
	vector<string> tmp;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> m;
		tmp.clear();
		for (int j = 0; j < m; ++j){
			cin >> bus_stop;
			tmp.push_back(bus_stop);
		}
		if (bus_routes.count(tmp)){
			cout << "Already exists for " << bus_routes[tmp] << endl;
		} else {
			bus_routes[tmp] = bus_routes.size() + 1;
			cout << "New bus " << bus_routes[tmp] << endl;
		}

	}
}

