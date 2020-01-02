#include <iostream>

using namespace std;


struct Specialization {
	string value;
	explicit Specialization(string s) {
		value = s;
	}
};

struct Course {
	string value;
	explicit Course(string s) {
		value = s;
	}
};

struct Week {
	string value;
	explicit Week(string s) {
		value = s;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(Specialization a, Course b, Week c) {
		specialization = a.value;
		course = b.value;
		week = c.value;
	}
};



int main() {

	//LectureTitle title(Specialization("C++"), Course("W"), Week("4"));

	return 1;
}
