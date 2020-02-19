#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;



int main() {

	int request_num;
	cin >> request_num;
	map<set<string>, int> route_num;
	for (int i = 0; i < request_num; ++i) {
		int num_of_stops;
		set<string> stop_names;
		cin >> num_of_stops;
		for (int j = 0; j < num_of_stops; j++) {
			string stop;
			cin >> stop;
			stop_names.insert(stop);
		}
		if (route_num.count(stop_names) > 0) {
			cout << "Already exists for " << route_num[stop_names] << "\n";
		}
		else {
			int route_num_new = route_num.size() + 1;
			route_num[stop_names] = route_num_new;
			cout << "New bus " << route_num_new << "\n";
		}
	}

	return 0;
}