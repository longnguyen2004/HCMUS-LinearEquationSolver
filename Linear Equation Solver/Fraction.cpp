#include "fraction.h"
#include <cmath>

int gcd(int a, int b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (a > b) return gcd(a % b, b);
	else return gcd(a, b % a);
}

struct Fraction {
	int _num, _den;
	Fraction(int num, int den) : _num(num), _den(den)
	{

	}
	void normalize()
	{
		int GCD = gcd(abs(_num), abs(_den));
		_num /= GCD;
		_den /= GCD;
		if (_den < 0) {
			_num = -_num;
			_den = -_den;
		}
	}
	Fraction operator+(const Fraction& rhs)
	{
		Fraction result(this->_num * rhs._den + this->_den * rhs._num, this->_den * rhs._den);
		result.normalize();
		return result;
	}
	Fraction operator-(const Fraction& rhs)
	{
		Fraction result(this->_num * rhs._den - this->_den * rhs._num, this->_den * rhs._den);
		result.normalize();
		return result;
	}
	Fraction operator*(const Fraction& rhs)
	{
		Fraction result(this->_num * rhs._num, this->_den * rhs._den);
		result.normalize();
		return result;
	}
	Fraction operator/(const Fraction& rhs)
	{
		Fraction result(this->_num * rhs._den, this->_den * rhs._num);
		result.normalize();
		return result;
	}
};
