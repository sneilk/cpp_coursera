/*
 * W4LectureTitle.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/PnvtW/struktura-lecturetitle
 */


#include <string>
using namespace std;
struct Specialization{
	string value;

	explicit Specialization(const string& specialization){
		value = specialization;
	}
};

struct Course{
	string value;

	explicit Course(const string& specialization){
		value = specialization;
	}
};

struct Week{
	string value;

	explicit Week(const string& specialization){
		value = specialization;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(const Specialization& s, const Course& c, const Week& w){
		specialization = s.value;
		course = c.value;
		week = w.value;
	}
};
