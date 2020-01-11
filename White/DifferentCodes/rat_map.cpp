#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		int nod = gcd(numerator, denominator);
		numerator /= nod;
		denominator /= nod;
		if (denominator < 0) {
			denominator *= -1;
			numerator *= -1;
		}
		p = numerator;
		q = denominator;
	}

	int Numerator() const {
		return p;
	}

	int Denominator() const {
		return q;
	}

private:
	int p;
	int q;
	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}
	// Добавьте поля
};

Rational operator* (const Rational& l, const Rational& r) {
	return Rational(l.Numerator() * r.Numerator(), r.Denominator() * l.Denominator());
}

Rational operator/ (const Rational& l, const Rational& r) {
	return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

bool operator== (const Rational& lhs, const Rational& rhs) {
	if ((lhs.Numerator() == rhs.Numerator()) & (lhs.Denominator() == rhs.Denominator()))
		return 1;
	return 0;
}

ostream& operator<< (ostream& s, const Rational& o) {
	s << o.Numerator() << "/" << o.Denominator();
	return s;
}

istream& operator>> (istream& s, Rational& o) {
	int num = o.Numerator();
	int den = o.Denominator();
	s >> num;
	s.ignore(1);
	s >> den;
	o = Rational(num, den);
	return s;
}

bool operator< (const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}
// Вставьте сюда реализацию operator == для класса Rational из второй части

// � еализуйте для класса Rational операторы * и /


int main() {
	{
		const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3) {
			cout << "Wrong amount of items in the set" << endl;
			return 1;
		}

		vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
			cout << "Rationals comparison works incorrectly" << endl;
			return 2;
		}
	}

	{
		map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			cout << "Wrong amount of items in the map" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}