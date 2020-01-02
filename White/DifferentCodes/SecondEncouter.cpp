#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	string in;
	int k = 0;
	cin >> in;
	if (in.size() == 0) {
		cout << "-2";
		return 1;
	}
	for (int i = 0; i < in.size(); i++) {
		if (k == 2) {
			cout << i - 1;
			break;
		}
		if (in[i] == 'f')
			k++;
	}
	if (k == 0)
		cout << "-2";
	else if (k == 1)
		cout << "-1";
	return 1;
}
