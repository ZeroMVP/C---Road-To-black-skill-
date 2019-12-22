#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>> buses;

void newBus() {

	string bus = "";
	string bus_stop = "";
	int stop_count = 0;
	vector<string> bus_stops;
	cin >> bus;
	cin >> stop_count;
	for (int i = 0; i < stop_count; i++) {
		cin >> bus_stop;
		bus_stops.push_back(bus_stop);
	}
	buses[bus] = bus_stops;
}

void allBuses() {

	if (buses.size() == 0) {
		cout << "No buses\n";
		return;
	}

	for (auto item : buses) {
		cout << "Bus " << item.first << ": ";
		for (string stops : item.second) {
			cout << stops << " ";
		}
		cout << "\n";
	}
}

string busesForStop(string stop, string bus_not_include) {

	string buses_answer;
	for (auto item : buses) {
		if (count(begin(item.second), end(item.second), stop) != 0) {
			if (item.first != bus_not_include) {
				buses_answer += item.first;
				buses_answer += " ";
			}
		}
	}

	return buses_answer;

}

void requestSystem(int number_of_requests) {

	for (int i = 0; i < number_of_requests; i++) {

		string request = "";
		cin >> request;
		if (request == "NEW_BUS") {
			newBus();
		}
		else if (request == "BUSES_FOR_STOP") {
			string stop_name = "";
			string buses_answer = "";
			cin >> stop_name;
			buses_answer = busesForStop(stop_name, "");
			if (buses_answer == "")
				cout << "No stop\n";
			else
				cout << buses_answer << "\n";
		}
		else if (request == "STOPS_FOR_BUS")
		{
			string bus_name = "";
			string answer;
			int num = 0;
			cin >> bus_name;
			for (auto item : buses) {
				if (item.first == bus_name)
					num += 1;
			}
			if (num == 0)
				cout << "No bus\n";
			else
			{
				for (auto item : buses[bus_name]) {
					answer = busesForStop(item, bus_name);
					if (answer == "")
						answer = "no interchange";
					cout << "Stop " << item << ": " << answer << "\n";
				}
			}
		}
		else
			allBuses();

	}
}


int main() {

	int number_of_requests = 0;
	cin >> number_of_requests;
	requestSystem(number_of_requests);
	return 1;
}