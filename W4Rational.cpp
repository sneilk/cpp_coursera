/*
 * W4Rational.cpp
 *
 *  Created on: Apr 13, 2020
 *      Author: sneilk
 *
 *  Task:
 *  https://www.coursera.org/learn/c-plus-plus-white/programming/pZwQ4/klass-rational
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
    	} else if (numerator == 0) {
    		p = numerator;
    		q = 1;
    	}
    	CutNumbers();
    }

    void SetNumerator(int num) {
    	if (num == 0) {
    		p = num;
    		q = 1;
    	} else {
    		p = num;
    	}
    	CutNumbers();
    }

    void SetDenominator(int denom) {
    	if (denom > 0) {
    		q = denom;
    	} else {
    		p = -p;
    		q = -denom;
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
	return {a.Numerator() * b.Denominator(),
			a.Denominator() * b.Numerator()};
}

istream& operator>>(istream& in, Rational& number) {
	char s = '/';
	int a, b;
	if (in >> a >> s >> b && s == '/'){
		cout << a << " " << b << endl;
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
