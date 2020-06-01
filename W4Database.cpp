/*
 * W4Database.cpp
 *
 *  Created on: Apr 17, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/sO7Vq/final-naia-zadacha-kursa
 *
 *
 *  Bugs:
 *
 *  1.
 *  inp: Add 1---1-1 5
 *  out: Wrong date format
 *  inp: Add 1-69-42
 *  out: Month value is invalid
 *  inp: Add 1---1-1 5
 *  out: Month value is invalid
 *
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

class Date{
public:
	Date(){

	}

	Date(int new_day, int new_month, int new_year){
		if (new_month < 1 || new_month > 12) {
			throw runtime_error("Month value is invalid: " + to_string(new_month));
		}
		int month_len = 31;
		if ((new_day < 1) || (new_day > month_len)) {
			throw runtime_error("Day value is invalid: " + to_string(new_day));
		}
		day = new_day;
		month = new_month;
		year = new_year;
	}
	  string GetYear() const{
		  int used_year = year;
		  int size = 4;
		  if (year < 0){
			  used_year *= -1;
			  size -= 1;
		  }

		  string s = to_string(used_year);
		  for (int i =0; size - s.size(); i++) {
			  s = '0' + s;
		  }
		  if (year < 0){
			  s = '-' + s;
		  }
		  return s;
	  }

	  string GetMonth() const{
		  string s = to_string(month);
		  for (int i =0; 2 - s.size(); i++) {
			  s = '0' + s;
		  }
		  return s;
	  }

	  string GetDay() const{
		  string s = to_string(day);
		  for (int i =0; 2 - s.size(); i++) {
			  s = '0' + s;
		  }
		  return s;
	  }



private:
	int day = 1;
	int month = 1;
	int year = 1900;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return (lhs.GetDay() < rhs.GetDay());
		} else {
			return lhs.GetMonth() < rhs.GetMonth();
		}
	} else {
		return lhs.GetYear() < rhs.GetYear();
	}
}

istream& operator>>(istream& in, Date& date){

	string data, s;
	int y, m, d;
	char c1, c2;
	in >> data;
	istringstream input(data);
	input >> y >> c1 >> m >> c2 >> d >> s;

	if (c1 != '-' || c2 != '-' || s != "") {
//		cout << y << " " << m << " " << d << s << endl;
//		cout << c1 << " " << c2 << endl;
		throw runtime_error("Wrong date format: " + data);
	} else {
//		cout << y << " " << m << " " << d << s << endl;
//		cout << c1 << " " << c2 << endl;
		date = Date(d, m, y);
	}
	return in;
}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.GetYear() << '-' << date.GetMonth() << '-' << date.GetDay();
	return out;
}


class Database{
public:

	void AddEvent(const Date& date, const string& event) {
		if (!IsInclude(events[date], event)) {
			events[date].insert(event);
		}
	}

	void DelEvent(const Date& date, const string& event){
		if (events.count(date) && IsInclude(events[date], event)) {
		    auto search = events[date].find(event);
		    if (search != events[date].end()){
		    	events[date].erase(search);
				cout << "Deleted successfully" << endl;
		    }
		    else {
		    	cout << "Error in deletion of event" << endl;
		    }
		} else {
			cout << "Event not found" << endl;
		}
	}

	void DelDate(const Date& date){
		int n = 0;
		if (events.count(date)) {
			n = events[date].size();
			events.erase(date);
			cout << "Deleted " << n << " events" << endl;
		} else {
			cout << "Deleted " << n << " events" << endl;
		}
	}

	void Find(const Date& date) const {
		if (events.count(date)) {
			for (const auto& i : events.at(date)) {
				cout << i << endl;
			}
		}
	}

	void Print() const {
		for (const auto& [key, val] : events) {
			for (const auto i : val) {
				cout << key << " " << i << endl;
			}
		}

	}

private:
	map<Date, set<string>> events;


	bool IsInclude(const set<string>& v, const string& event) const {
		return (find(v.begin(), v.end(), event) != v.end());
	}
};

void DatabaseInteracrion(){
	  Database db;

	  string command;
	  while (getline(cin, command)) {
		  istringstream input(command);
		  if (input) {
			  input >> command;

			  if (command == "Add") {
				  Date d;
				  string event;
				  try {
					  input >> d >> event;
					  db.AddEvent(d, event);
				  }
				  catch (runtime_error& ex) {
					  cout << ex.what() << endl;
				  }
			  } else if (command == "Del") {
				  Date d;
				  string event;
				  try {
					  input >> d >> event;
					  if (event.size()) {
						  db.DelEvent(d, event);
					  } else {
						  db.DelDate(d);
					  }
				  }
				  catch (runtime_error& ex) {
					  cout << ex.what() << endl;
				  }
			  } else if (command == "Find") {
				  try {
					  Date d;
					  input >> d;
					  db.Find(d);
				  }
				  catch (runtime_error& ex) {
					  cout << ex.what() << endl;
				  }
			  } else if (command == "Print") {
				  db.Print();
			  } else if (command != ""){
				  cout << "Unknown command: " << command << endl;
			  }
		  }
	  }
}

int main(){
	DatabaseInteracrion();
	return 0;
}

