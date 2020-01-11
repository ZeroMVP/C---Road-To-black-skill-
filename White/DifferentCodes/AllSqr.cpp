#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;
// Предварительное объявление шаблонных функций
template<typename T> T Sqr(T x);

template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);

template <typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2);

template <typename T1, typename T2>
map<T1, T2> operator * (const map<T1, T2>& v1, const map<T1, T2>& v2);


// Объявляем шаблонные функции
template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
	First f = p1.first * p2.first;
	Second s = p2.second * p2.second;
	return make_pair(f, s);
}

template <typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2) {
	vector<T> answer;
	for (size_t i = 0; i < v1.size(); i++) {
		answer.push_back(v1[i] * v2[i]);
	}
	return answer;
}

template <typename T1, typename T2>
map<T1, T2> operator * (const map<T1, T2>& v1, const map<T1, T2>& v2) {
	map<T1, T2> answer;
	for (const auto& x : v1) {
		answer[x.first] = x.second * v2.at(x.first);
	}
	return answer;

}

template <typename T>
T Sqr(T x) {
	return x * x;
}


int main() {
	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
}