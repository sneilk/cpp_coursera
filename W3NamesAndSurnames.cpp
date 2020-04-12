/*
 * W3NamesAndSurnames.cpp
 *
 *  Created on: Apr 12, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/4FQn4/imiena-i-familii-1
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/aN8U1/imiena-i-familii-2
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
  void ChangeFirstName(int year, const string& first_name) {
	  name_changes[year]["first_name"] = first_name;
	  first_name_changes.push_back(year);
  }
  void ChangeLastName(int year, const string& last_name) {

	  name_changes[year]["last_name"] = last_name;
	  last_name_changes.push_back(year);
  }
  string GetFullName(int year) {
	  int f_name_year = LastYear(year, first_name_changes);
	  int s_name_year = LastYear(year, last_name_changes);

	  if (f_name_year && s_name_year){
		  string first_name = name_changes[f_name_year]["first_name"];
		  string second_name = name_changes[s_name_year]["last_name"];
		  return first_name + " " + second_name;
	  } else if (f_name_year) {
		  return name_changes[f_name_year]["first_name"] + " with unknown last name";
	  } else if (s_name_year) {
		  return name_changes[s_name_year]["last_name"] +" with unknown first name";
	  } else {
		  return "Incognito";
	  }
  }

  string GetFullNameWithHistory(int year) {
	  string f_names = PrevYears(year, first_name_changes, true);
	  string s_names = PrevYears(year, last_name_changes, false);
	  int f_name_year = LastYear(year, first_name_changes);
	  int s_name_year = LastYear(year, last_name_changes);

	  if (f_name_year && s_name_year){
		  string first_name = name_changes[f_name_year]["first_name"] + f_names;
		  string second_name = name_changes[s_name_year]["last_name"] + s_names;
		  return first_name + " " + second_name;
	  } else if (f_name_year) {
		  return name_changes[f_name_year]["first_name"] + f_names + " with unknown last name";
	  } else if (s_name_year) {
		  return name_changes[s_name_year]["last_name"] + s_names +" with unknown first name";
	  } else {
		  return "Incognito";
	  }
  }

private:
  map<int, map<string, string>> name_changes;
  vector<int> first_name_changes, last_name_changes;

  int LastYear(const int& year, const vector<int>& v){
	  int result = 0;
	  for (const auto& i: v){
		  if (i <= year && i > result){
			  result = i;
		  }
	  }
	  return result;
  }
  string PrevYears(const int& year, const vector<int>& v, bool IsFirstName){
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
			  buff = name_changes[i]["first_name"];

		  } else {
			  buff = name_changes[i]["last_name"];
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

