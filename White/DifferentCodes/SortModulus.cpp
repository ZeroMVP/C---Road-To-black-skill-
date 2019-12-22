#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& v) {

	for (auto g : v) {
		cout << g << " ";
	}
	cout << endl;
}

bool Compare(int a, int b) { return (a * a < b * b); }

int main() {

	int size = 0;
	int temp = 0;
	vector<int> to_sort;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> temp;
		to_sort.push_back(temp);
	}
	printVector(to_sort);
	sort(begin(to_sort), end(to_sort), Compare);
	printVector(to_sort);
}

