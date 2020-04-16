/*
 * W4Rational.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/pZwQ4/klass-rational
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/7p79I/iskliuchieniia-v-klassie-rational
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/bshor/kal-kuliator-obyknoviennykh-drobiei
 *
 */

#include <iostream>
#include <ostream>
#include <istream>
using namespace std;

class Rational {
public:
    Rational() {
    	p = 0;
    	q = 1;
    }

    Rational(int numerator, int denominator) {
    	if ((numerator > 0 && denominator > 0) ||
    		(numerator < 0 && denominator > 0)) {
    		p = numerator;
    		q = denominator;
    	} else if ((numerator > 0 && denominator < 0) ||
    				(numerator < 0 && denominator < 0)) {
    		p = numerator * -1;
    		q = denominator * -1;
    	} else if (denominator == 0){
    		throw invalid_argument("Denominator must not be 0.");
    	} else if (numerator == 0) {
    		p = numerator;
    		q = 1;
    	}
    	CutNumbers();
    }

    int Numerator() const {
    	return p;
    }

    int Denominator() const {
    	return q;
    }

private:
    int q;
    int p;

    void CutNumbers(){
    	int a = abs(p);
    	int b = q;

    	while (a && b){
    		a > b ? a %= b : b %= a;
    	}
    	a += b;
    	p /= a;
    	q /= a;
    }
};

bool operator==(const Rational& a, const Rational& b) {
	return ((a.Numerator() == b.Numerator()) &&
			(a.Denominator() == b.Denominator()));
}

Rational operator+(const Rational& a, const Rational& b){
	return {a.Numerator() * b.Denominator() + a.Denominator() * b.Numerator(),
			a.Denominator() * b.Denominator()};

}

Rational operator-(const Rational& a, const Rational& b) {
	return {a.Numerator() * b.Denominator() - a.Denominator() * b.Numerator(),
			a.Denominator() * b.Denominator()};
}

Rational operator*(const Rational& a, const Rational& b) {
	return {a.Numerator() * b.Numerator(),
			a.Denominator() * b.Denominator()};
}

Rational operator/(const Rational& a, const Rational& b) {
	if (b.Numerator() == 0) {
		throw domain_error("Divisor must not be 0");
	}
	return {a.Numerator() * b.Denominator(),
			a.Denominator() * b.Numerator()};
}

istream& operator>>(istream& in, Rational& number) {
	char s = '/';
	int a, b;
	if (in >> a >> s >> b && s == '/'){
		number = {a, b};
	}
	return in;
}

ostream& operator<<(ostream& out, const Rational& number) {
	out << number.Numerator() << "/" << number.Denominator();
	return out;
}

bool operator>(const Rational& num1, const Rational& num2){
	return (num1.Numerator() * num2.Denominator() >
			num2.Numerator() * num1.Denominator());
}

bool operator<(const Rational& num1, const Rational& num2){
	return (num1.Numerator() * num2.Denominator() <
			num2.Numerator() * num1.Denominator());
}

void Calculator(){
	char operation;
	Rational a, b;
	try {
		cin >> a >> operation >> b;
		if (operation == '+') {
			cout << a + b;
		} else if (operation == '-') {
			cout << a - b;
		} else if (operation == '*') {
			cout << a * b;
		} else if (operation == '/') {
			cout << a / b;
		}
	} catch (domain_error& e) {
		 cout << "Division by zero";
	} catch (invalid_argument& e) {
		cout << "Invalid argument";
	}

}

