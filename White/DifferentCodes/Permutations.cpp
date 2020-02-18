#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void outVector(const vector<int>& b) {
	for (int a : b)
		cout << a << " ";
	cout << "\n";
}

int main() {

	vector<int> mut;
	int permut = 0;
	cin >> permut;
	for (int i = 0; i < permut; i++)
		mut.push_back(permut - i);

	do {
		outVector(mut);
	} while (prev_permutation(begin(mut), end(mut)));


	return 0;
}
