#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int density = 0;
	int w = 0;
	int h = 0;
	int d = 0;
	uint64_t mass = 0;
	uint64_t volume = 0;

	cin >> n;
	cin >> density;

	for (int i = 0; i < n; i++) {
		cin >> w;
		cin >> h;
		cin >> d;
		volume = static_cast<uint64_t>(w) * h * d;
		mass += volume * density;
	}

	cout << mass;
	return 1;
}