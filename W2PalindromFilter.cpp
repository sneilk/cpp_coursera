/*
 * W2PalindromFilter.cpp
 *
 *  Created on: Apr 9, 2020
 *      Author: sneilk
 */

#include <iostream>
#include <string>
#include <vector>

bool IsPalindrom(std::string s){

	  for (unsigned int i = 0; i < s.size() / 2; i++) {
		  if (s[i] != s[s.size() - 1 - i]) {
			  return false;
		  }
	  }

	  return true;
}

std::vector<std::string> PalindromFilter(
		std::vector<std::string> words, int minLength) {

	std::vector<std::string> result;

	for (auto word: words){
		if (IsPalindrom(word) && (minLength <=0 || word.size() >= minLength)){
			result.push_back(word);
		}
	}
	return result;
}



























