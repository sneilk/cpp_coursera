/*
 * W3NamesAndSurnames.cpp
 *
 *  Created on: Apr 12, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/4FQn4/imiena-i-familii-1
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/aN8U1/imiena-i-familii-2
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/6rEoc/imiena-i-familii-3
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Person {
public:

	Person(const string& name, const string& l_name, const int& year){
		name_changes[year]["last_name"] = l_name;
		name_changes[year]["first_name"] = name;
		last_name_changes.push_back(year);
		first_name_changes.push_back(year);
		birth_year = year;
	}

	void ChangeFirstName(const int year, const string& first_name) {
		if (year >= birth_year) {
			name_changes[year]["first_name"] = first_name;
			first_name_changes.push_back(year);
		}
	}

	void ChangeLastName(const int& year, const string& last_name) {
		if (year >= birth_year) {
			name_changes[year]["last_name"] = last_name;
			last_name_changes.push_back(year);
		}
	}
	string GetFullName(const int& year) const {
		if (year < birth_year) {
			return "No person";
		}
		const int f_name_year = LastYear(year, first_name_changes);
		const int s_name_year = LastYear(year, last_name_changes);

		return CreateMessage(
				name_changes.at(f_name_year).at("first_name"),
				name_changes.at(s_name_year).at("last_name"));
	}

	string GetFullNameWithHistory(const int& year) const {
		if (year < birth_year) {
			return "No person";
		}
		const string f_names = PrevYears(year, first_name_changes, true);
		const string s_names = PrevYears(year, last_name_changes, false);
		const int f_name_year = LastYear(year, first_name_changes);
		const int s_name_year = LastYear(year, last_name_changes);

		return CreateMessageHistory(
						name_changes.at(f_name_year).at("first_name"),
						name_changes.at(s_name_year).at("last_name"),
						f_names, s_names);
	}

private:
	int birth_year;
	map<int, map<string, string>> name_changes;
	vector<int> first_name_changes, last_name_changes;

	string CreateMessage(const string& first_name, const string& second_name) const {
		if (first_name.empty() && second_name.empty()){
			return "Incognito";
		} else if (second_name.empty()) {
			return first_name + " with unknown last name";
		} else if (first_name.empty()) {
			return second_name +" with unknown first name";
		} else {
			return first_name + " " + second_name;
		}
	}

	string CreateMessageHistory(
			const string& first_name,
			const string& second_name,
			const string& f_names,
			const string s_names) const {

		if (first_name.empty() && second_name.empty()){
			return "Incognito";
		} else if (second_name.empty()) {
			return first_name + f_names + " with unknown last name";
		} else if (first_name.empty()) {
			return second_name + s_names + " with unknown first name";
		} else {
			return first_name + f_names + " " + second_name + s_names;
		}
	}

	int LastYear(const int& year, const vector<int>& v) const {
		int result = 0;
		for (const auto& i: v){
			if (i <= year && i > result){
				result = i;
			}
		}
		return result;
	}

	string PrevYears(const int& year, const vector<int>& v, bool IsFirstName) const {
		vector<int> years;
		for (const auto& i: v){
			if (i <= year){
				years.push_back(i);
			}
		}
		sort(begin(years), end(years), [](int a, int b){return (a>b);});

		vector<string> names;
		string buff, last_name;
		for (const auto& i : years) {

			if (IsFirstName) {
				buff = name_changes.at(i).at("first_name");
			} else {
				buff = name_changes.at(i).at("last_name");
			}

			if (buff != last_name){
				names.push_back(buff);
				last_name=buff;
			}
		}

		if (names.size() > 1) {
			string result = " (";
			for (int i = 1; i < names.size(); i++){
				if (i > 1) {
					result += ", ";
				}
				result += names[i];
			}
			result += ")";
			return result;
		}
		return "";
	}
};

