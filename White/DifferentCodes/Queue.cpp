#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void callParser(vector<int>& queue) {

	string command = "";
	int order = 0;
	cin >> command;
	if (command == "WORRY") {
		cin >> order;
		queue[order] = 1;
	}
	else if (command == "QUIET") {
		cin >> order;
		queue[order] = 0;
	}
	else if (command == "COME") {
		cin >> order;
		if (order >= 0)
			for (int i = 0; i < order; i++)
				queue.push_back(0);
		else
			queue.resize(queue.size() + order);
	}
	else
		cout << count(begin(queue), end(queue), 1) << "\n";
}


int main() {

	vector<int> queue;

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		callParser(queue);
	}
	return 1;
}