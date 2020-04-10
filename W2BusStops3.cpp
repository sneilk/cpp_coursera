/*
 * W2BusStops3.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/F7WBk/avtobusnyie-ostanovki-3
 */

#include <iostream>
#include <map>
#include <set>
using namespace std;

void BusStopIII(){
	int n, m;
	map<set<string>, int> bus_routes;
	set<string> tmp;
	string bus_stop;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> m;
		tmp.clear();
		for (int j = 0; j < m; ++j){
			cin >> bus_stop;
			tmp.insert(bus_stop);
		}
		if (bus_routes.count(tmp)){
			cout << "Already exists for " << bus_routes[tmp] << endl;
		} else {
			bus_routes[tmp] = bus_routes.size() + 1;
			cout << "New bus " << bus_routes[tmp] << endl;
		}
	}
}

int main(){
	BusStopIII();
	return 0;
}

