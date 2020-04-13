/*
 * W4StudentsList.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/4X4vH/spisok-studientov
 */

#include <iostream>
#include <vector>
using namespace std;

struct Date{
	int day;
	int month;
	int year;
};

struct Student{
	string name;
	string surname;
	Date birthday;
};

void Students(){
	int n;
	vector<Student> students;

	cin >> n;
	for (int i = 0; i < n; ++i){
		string name, surname, s;
		int d, m, y;
		cin >> name;
		cin >> surname;
		cin >> d;
		cin >> m;
		cin >> y;
		students.push_back({name, surname, {d, m, y}});
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string request, s;
		int num;

		cin >> request;
		cin >> num;

		num -= 1;
		if (request == "date" && num >= 0 && num < students.size()) {
			cout << students[num].birthday.day << '.'
					<< students[num].birthday.month  << '.'
					<< students[num].birthday.year << endl;
		} else if (request == "name" && num >= 0 && num < students.size()) {
			cout << students[num].name << ' ' << students[num].surname << endl;
		} else {
			cout << "bad request" << endl;
		}
	}
}

