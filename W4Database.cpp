/*
 * W4Database.cpp
 *
 *  Created on: Apr 17, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/sO7Vq/final-naia-zadacha-kursa
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

class Date{
public:
	Date(){

	}

	Date(int new_day, int new_month, int new_year){
		if (new_month < 1 || new_month > 12) {
			cout << "Month value is invalid: " << new_month << endl;

			// ToDo: use exception

		}
		int month_len = 31;
		if ((new_day < 1) || (new_day > month_len)) {
			cout << "Day value is invalid: " << new_day << endl;

			// ToDo: use exception

		}
		day = new_day;
		month = new_month;
		year = new_year;
	}
	  int GetYear() const{
		  return year;
	  }

	  int GetMonth() const{
		  return month;
	  }

	  int GetDay() const{
		  return day;
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

	string s, data;
	int y, m, d;
	char c1, c2;
	in >> data;
	istringstream input(data);
	char c = input.peek();
	if (c == '-') {
		input.ignore(1);
		input >> y ;
		y *= -1;
	} else {
		input >> y;
	}
	input >> c1 >> m >> c2 >> d;

	if (c1 != '-' || c2 != '-') {
		cout << "Wrond date fomat: " << data;

		// ToDo: use exception

	} else {
			date = Date(d, m, y);
	}
	return in;
}


class Database{
public:

	void AddEvent(const Date& date, const string& event) {
		if (!IsInclude(events[date], event)) {
			events[date].push_back(event);
			sort(begin(events[date]), end(events[date]));
		}
	}

	void DelEvent(const Date& date, const string& event){
		if (events.count(date) && IsInclude(events[date], event)) {
			cout << "Deleted successfully" << endl;
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
				cout << i << " ";
			}
			cout << endl;
		}
	}

	void Print() const {
		for (const auto& [key, val] : events) {
			for (const auto i : val) {
				cout << key.GetYear() << '-' <<
						key.GetMonth() << '-' <<
						key.GetDay() << " " << i << endl;
			}
		}

	}

private:
	map<Date, vector<string>> events;


	bool IsInclude(const vector<string>& v, const string& event) const {
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
				  input >> d >> event;
				  db.AddEvent(d, event);
			  } else if (command == "Del") {
				  Date d;
				  string event;
				  input >> d >> event;
				  if (event.size()) {
					  db.DelEvent(d, event);
				  } else {
					  db.DelDate(d);
				  }
			  } else if (command == "Find") {
				  Date d;
  				  input >> d;
  				  db.Find(d);

			  } else if (command == "Print") {
				  db.Print();
			  }
		  }
	  }
}

int main(){
	DatabaseInteracrion();
	return 0;
}


