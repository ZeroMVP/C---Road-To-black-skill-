#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	
	vector<string> answer;
	auto it = begin(s);
	while (it != end(s)) {
		auto word = it;
		it = find(it, end(s), ' ');
		answer.push_back(string(word, it));
		if (it == end(s))
			break;
		it++;
	}
	return answer;

}



int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}