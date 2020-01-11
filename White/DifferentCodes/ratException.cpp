#include <iostream>
#include <exception>
using namespace std;

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0)
			throw invalid_argument("gg");
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
	if (r.Numerator() == 0)
		throw domain_error("bad right numerator");
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


int main() {
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) {
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) {
	}

	cout << "OK" << endl;
	return 0;
}