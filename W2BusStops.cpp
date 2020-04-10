/*
 * W2BusStops.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/Gi9dw/avtobusnyie-ostanovki-1
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void AllBuses(const map<string, vector<string>>& bus){
	if (bus.size()) {
		for (const auto& [key, val] : bus){
			cout << "Bus " << key << ": ";
			for (const auto& i : val) {
				cout << i << " ";
			}
			cout << endl;
		}
	} else {
		cout << "No buses" << endl;
	}
}


void BusesForStop(map<string, vector<string>>& stops){
	string bus_stop;

	cin >> bus_stop;
	if (stops.count(bus_stop)) {
		for (const auto& v : stops[bus_stop]) {
			cout << v << " ";
		}
	} else {
		cout << "No stop";
	}
	cout << endl;
}


void NewBus(map<string, vector<string>>& bus, map<string, vector<string>>& stops){
	int n;
	string route, bus_stop;

	cin >> route >> n;
	for (int i = 0; i < n; ++i){
		cin >> bus_stop;
		bus[route].push_back(bus_stop);
		stops[bus_stop].push_back(route);
	}
}


void StopsForBus(map<string, vector<string>>& bus, map<string, vector<string>>& stops){
	string route;

	cin >> route;
	if (bus.count(route)) {
		for (const auto& i : bus[route]) {
			cout << "Stop " << i << ": ";
			if (stops[i].size() > 1) {
				for (const auto& j : stops[i]){
					if (j != route) {
						cout << j << " ";
					}
				}
			} else if (stops[i].size() == 1){
				cout << "no interchange";
			} else {
				cout << "ERROR!";
			}
			cout << endl;
		}
	} else {
		cout << "No bus" << endl;
	}
}


void BusStops(){
	int n;
	map<string, vector<string>> bus, stops;
	string request;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> request;
		if (request == "NEW_BUS"){
			NewBus(bus, stops);
		} else if (request == "BUSES_FOR_STOP") {
			BusesForStop(stops);
		} else if (request == "STOPS_FOR_BUS") {
			StopsForBus(bus, stops);
		} else if (request == "ALL_BUSES") {
			AllBuses(bus);
		}
	}
}

