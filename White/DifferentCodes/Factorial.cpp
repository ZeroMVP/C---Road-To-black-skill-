#include <iostream>

using namespace std;

int Factorial(int size) {

	if (size <= 0) {
		return 1;
	}
	int k = 1;
	for (int i = 1; i <= size; i++) {
		k *= i;
	}
	return k;
}

int main() {
	cout << Factorial(0);
}