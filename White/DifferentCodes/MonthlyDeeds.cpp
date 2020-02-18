#include <math.h>
#include <iostream>
#include <vector>
using namespace std;


const vector<int> monthLen = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int monthNow = 0;

int main() {
	int num_of_operations = 0;
	cin >> num_of_operations;

	vector<vector<string>> scedule(monthLen[monthNow]);
	for (int i = 0; i < num_of_operations; ++i) {
		string operation;
		int day = 0;
		cin >> operation;
		//operations
		if (operation == "ADD") {
			string deed;
			cin >> day >> deed;
			day--;
			scedule[day].push_back(deed);
		}
		else if (operation == "DUMP") {
			cin >> day;
			day--;
			cout << size(scedule[day]) << " ";
			for (string d : scedule[day]) {
				cout << d << " ";
			}
			cout << "\n";
		}
		else {
			int current = monthNow;
			monthNow = (monthNow + 1) % 12;
			if (monthLen[current] > monthLen[monthNow]) {

				for (int j = monthLen[monthNow]; j < monthLen[current]; j++) {
					for (string d : scedule[j]) {
						scedule[monthLen[monthNow] - 1].push_back(d);
					}
					scedule[j].erase(begin(scedule[j]), end(scedule[j]));
				}
				//scedule.erase(begin(scedule) + 29, end(scedule));
			}


		}

	}

	return 0;
}