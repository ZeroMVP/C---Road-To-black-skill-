#include <iostream>
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

Rational operator+ (const Rational& lhs, const Rational& rhs) {
	int num = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
	int den = lhs.Denominator() * rhs.Denominator();
	return Rational(num, den);
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

bool operator== (const Rational& lhs, const Rational& rhs) {
	if ((lhs.Numerator() == rhs.Numerator()) & (lhs.Denominator() == rhs.Denominator()))
		return 1;
	return 0;
}

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}