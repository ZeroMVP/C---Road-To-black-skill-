#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {


	int n = 0;
	long double now = 0;
	long double avg = 0;
	cin >> n;
	vector<long double> temp;
	vector<int> idx;
	for (int i = 0; i < n; i++) {
		cin >> now;
		avg += now;
		temp.push_back(now);
	}
	avg /= n;
	n = 0;
	int k = 0;
	for (auto day : temp) {
		if (day > avg) {
			k++;
			idx.push_back(n);
		}

		n++;
	}
	cout << k << "\n";
	for (int day : idx) {
		cout << day << " ";
	}
}