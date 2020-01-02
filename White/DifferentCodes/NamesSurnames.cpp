#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>


using namespace std;



class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		years_first.insert(year);
		history_first[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		years_last.insert(year);
		history_last[year] = last_name;
	}
	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
		int year_first_in = years_first.count(year);
		int year_last_in = years_last.count(year);
		if ((year_first_in != 0) & (year_last_in != 0))
			return history_first[year] + " " + history_last[year];
		else if ((year_first_in == 0) & (year_last_in != 0)) {
			int near_first = getMinYear(year, 1);
			if (near_first == -1)
				return history_last[year] + " with unknown first name";
			return history_first[near_first] + " " + history_last[year];
		}
		else if ((year_first_in != 0) & (year_last_in == 0)) {
			int near_last = getMinYear(year, 0);
			if (near_last == -1)
				return history_first[year] + " with unknown last name";
			return history_first[year] + " " + history_last[near_last];
		}
		else {
			int near_first = getMinYear(year, 1);
			int near_last = getMinYear(year, 0);
			if ((near_first == -1) & (near_last == -1))
				return "Incognito";
			else if ((near_first != -1) & (near_last == -1))
				return history_first[near_first] + " with unknown last name";
			else if ((near_first == -1) & (near_last != -1))
				return history_last[near_last] + " with unknown first name";
			return history_first[near_first] + " " + history_last[near_last];
		}
	}
private:
	// приватные поля
	map<int, string> history_first = { {-1, " with unknown first name"} };
	map<int, string> history_last = { {-1, " with unknown last name"} };
	set<int> years_first;
	set<int> years_last;

	int getMinYear(int year, int key) {
		int near_year = -1;

		for (auto item : (key ? years_first : years_last)) {
			//cout << item;
			if (item < year)
				if (item > near_year)
					near_year = item;
		}
		return near_year;
	}
};


int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}
