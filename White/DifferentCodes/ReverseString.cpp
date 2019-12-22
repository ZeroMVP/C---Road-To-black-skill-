#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class ReversibleString {

public:

	ReversibleString(const string& name) {
		string_class = name;
	}

	ReversibleString() {
		string_class = "";
	}

	string ToString() const {
		return string_class;
	}

	void Reverse() {
		reverse(begin(string_class), end(string_class));
	}

private:
	string string_class;
};


int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}