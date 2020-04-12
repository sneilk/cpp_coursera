/*
 * W3StringSortClass.cpp
 *
 *  Created on: Apr 12, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/c3YTB/otsortirovannyie-stroki
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class SortedStrings {
public:

  void AddString(const string& s) {
    sorted_strings.push_back(s);
  }

  vector<string> GetSortedStrings() {
	 StringsSort();
  	 return sorted_strings;
  }

private:
  vector<string> sorted_strings;

  string Lower(string s1){
  	for (auto& i : s1){
  		i = ::tolower(i);
  	}
  	return s1;
  }

  void StringsSort(){
	sort(begin(sorted_strings), end(sorted_strings));
  }
};


