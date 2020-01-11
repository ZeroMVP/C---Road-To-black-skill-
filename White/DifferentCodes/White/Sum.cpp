#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;





int main() {

	vector<int> a = { 1, 2, 3, 4, 5, 3, 4 };
	auto b = find(begin(a), end(a), 3);
	cout << *b;
	return 0;
}