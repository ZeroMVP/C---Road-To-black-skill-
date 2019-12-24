#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	float a, b, c, disc;
	cin >> a;
	cin >> b;
	cin >> c;
	disc = b * b - 4 * a * c;
	if (a == 0)
		cout << -c / b;
	else {
		if (disc < 0)
			cout << "";
		else if (disc == 0)
			cout << -b / (2 * a);
		else
			cout << (-b + sqrt(disc)) / (2 * a) << " " << (-b - sqrt(disc)) / (2 * a);
	}
	return 1;
}