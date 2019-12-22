#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> reversed;

	for (int i = v.size() - 1; i >= 0; --i) {
		reversed.push_back(v[i]);
	}

	return reversed;
}



void PrintVector(const vector<int>& v) {
	for (auto g : v) {
		cout << g << " ";
	}
}

class Secret {
private:
	int secr = 5;

public:

	void GetSecret() {
		cout << secr;
	}

	int& GetSecretLink() {
		return secr;
	}
};

int main() {

	vector<int> myVector = { 1, 5, 3, 2 };
	vector<int> b;
	PrintVector(myVector);
	b = Reversed(myVector);
	PrintVector(b);
}