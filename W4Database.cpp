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
#include <vector>
using namespace std;

class Date{
public:
	Date(){

	}

	Date(unsigned int new_day, unsigned int new_month, unsigned int new_year){
		if (new_month < 1 || new_month > 12) {
			cout << "Month value is invalid: " << new_month << endl;
		}
		int month_len = months_days[new_month - 1];
		if (new_year % 100 && new_year % 4 == 0 && new_month == 2) {
			month_len +=1;
		}
		if ((new_day < 1) || (new_day > month_len)) {
			cout << "Day value is invalid: " << new_day << endl;
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
	vector<int> months_days = {
			31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
			cout << date.GetYear() << '-' <<
					date.GetMonth() << '-' <<
					date.GetDay() << " ";
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

		  // Split command by spaces

		  if (command == "Add") {

		  } else if (command == "Del") {

		  } else if (command == "Find") {

		  } else if (command == "Print") {

		  }
	  }
}

int main(){
	DatabaseInteracrion();
	return 0;
}


