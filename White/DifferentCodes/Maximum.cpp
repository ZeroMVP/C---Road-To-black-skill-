#include <iostream>

using namespace std;

void UpdateIfGreater(int& a, int& b) {
	if (a > b) {
		b = a;
	}
}

int main() {
	int a = 0;
	int b = 0;
	cin >> a >> b;
	UpdateIfGreater(a, b);
	cout << "a: " << a << " b: " << b;
}