#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

void busesForStop(string stop_name, map<string, vector<string>> stop_buses) {

	string answer = "";
	if (size(stop_buses[stop_name]) == 0)
		answer = "No stop";
	else {
		for (string name : stop_buses[stop_name])
			answer = answer + name + " ";
	}
	answer += "\n";
	cout << answer;

}

void stopsForBus(string bus_name, map<string, vector<string>> stop_buses, map<string, vector<string>> bus_stops) {

	for (auto stop : bus_stops[bus_name]) {
		string answer = "Stop " + stop + ": ";
		string check = "Stop " + stop + ": ";
		for (auto bus : stop_buses[stop]) {
			if (bus != bus_name)
				answer = answer + bus + " ";
		}
		if (answer == check)
			answer += "no interchange";
		answer += "\n";
		cout << answer;
	}
}

void allBuses(map<string, vector<string>> bus_stops) {

	if (size(bus_stops) == 0) {
		cout << "No buses\n";
		return;
	}
	for (auto item : bus_stops) {
		string answer = "Bus " + item.first + ": ";
		for (auto stop : item.second)
			answer = answer + stop + " ";
		answer += "\n";
		cout << answer;
	}

}

int main() {


	map<string, vector<string>> bus_stops, stop_buses;
	int num_of_requests = 0;
	cin >> num_of_requests;
	for (int i = 0; i < num_of_requests; ++i) {
		string request;
		cin >> request; 
		
		if (request == "NEW_BUS") {
			string bus_name;
			cin >> bus_name;
			int stop_count;
			cin >> stop_count;
			for (int j = 0; j < stop_count; ++j) {
				string stop_name;
				cin >> stop_name;
				bus_stops[bus_name].push_back(stop_name);
				stop_buses[stop_name].push_back(bus_name);
			}
		}
		else if (request == "BUSES_FOR_STOP") {
			string stop_name;
			cin >> stop_name;
			busesForStop(stop_name, stop_buses);
		}
		else if (request == "ALL_BUSES")
			allBuses(bus_stops);
		else {
			string bus_name;
			cin >> bus_name;
			if (bus_stops.count(bus_name) == 0)
				cout << "No bus\n";
			else
				stopsForBus(bus_name, stop_buses, bus_stops);
		}
	}
	return 0;
}