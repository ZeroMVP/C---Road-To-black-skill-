#include <iostream>
#include <map>
#include <fstream>
#include <set>

using namespace std;


class Date {
public:
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}

	int day;
	int month;
	int year;
};

istream& operator>>(istream& stream, Date& date) {
	stream >> date.year;
	stream.ignore(1);
	stream >> date.month;
	stream.ignore(1);
	stream >> date.day;
	return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear())
		return lhs.GetYear() < rhs.GetYear();
	if (lhs.GetMonth() != rhs.GetMonth())
		return lhs.GetMonth() < rhs.GetMonth();
	return lhs.GetDay() < rhs.GetDay();

};

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data_base[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {

	}
	int  DeleteDate(const Date& date);

	void Find(const Date& date) const {
		string answer = "";
		set<string> temp;
		temp = data_base.at(date);
		for (auto elem : temp) {
			answer += elem;
			answer += "\n";
		}
		cout << answer;
	}



	void Print() const;

private:
	map<Date, set<string>> data_base;
};

int main() {
	Database db;

	int commands = 0;
	string command;
	Date date_new;
	string event_new;
	cin >> commands;
	for (int i = 0; i < commands; i++) {
		cin >> command;
		if (command == "add") {
			cin >> date_new;
			cin >> event_new;
			db.AddEvent(date_new, event_new);
		}
		else if (command == "find") {
			cin >> date_new;
			db.Find(date_new);
		}
	}


	return 0;
}