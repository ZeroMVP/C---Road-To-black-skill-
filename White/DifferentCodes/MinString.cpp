#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<string> res;
	string a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	a = min(a, b);
	a = min(a, c);
	cout << a;

	return 1;
}