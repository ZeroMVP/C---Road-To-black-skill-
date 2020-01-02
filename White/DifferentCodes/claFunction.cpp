#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class FunctionPart {

public:
	FunctionPart(char new_operation, double new_value) {
		operation = new_operation;
		value = new_value;
	}

	double Apply(double source_value) const {
		if (operation == '+')
			return source_value + value;
		else if (operation == '-')
			return source_value - value;
		else if (operation == '*')
			return source_value * value;
		else if (operation == '/')
			return source_value / value;
	}

	void Invert() {
		if (operation == '+')
			operation = '-';
		else if (operation == '-')
			operation = '+';
		else if (operation == '*')
			operation = '/';
		else
			operation = '*';

	}

private:
	char operation;
	double value;
};


class Function {

public:

	void AddPart(char operation, double values) {
		parts.push_back(FunctionPart(operation, values));
	}

	double Apply(double value) const {

		for (const FunctionPart& part : parts)
			value = part.Apply(value);

		return value;
	}

	void Invert() {
		for (FunctionPart& part : parts)
			part.Invert();
		reverse(begin(parts), end(parts));
	}

private:
	vector<FunctionPart> parts;
};


int main() {
	cout << 5 / 5;
	return 1;
}