#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

void PrintVectorPart(const vector<int>& numbers) {

	for (auto it = begin(numbers); it != end(numbers); ++it) {
		if (*it < 0) {
			while (it != begin(numbers)) {
				--it;
				cout << *it << " ";
			}
			return;
		}
	}
	auto b = end(numbers);
	while (b != begin(numbers)) {
		--b;
		cout << *b << " ";
	}
	return;
}

int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}
