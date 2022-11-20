#include "fraction.h"
#include <cmath>
#include <iostream>

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

Fraction::Fraction(long long num, long long den) : _num(num), _den(den)
{
	this->normalize();
}

void Fraction::normalize()
{
	long long gcd = GCD(std::abs(_num), std::abs(_den));
	_num /= gcd;
	_den /= gcd;
	if (_den < 0)
	{
		_num *= -1;
		_den *= -1;
	}
}

// Returns the numerator and denominator
long long Fraction::num() const { return _num; }
long long Fraction::den() const { return _den; }

// Returns the inverse fraction
Fraction Fraction::inverse() const
{
	return Fraction(this->_den, this->_num);
}

// Unary minus: Returns -a
Fraction Fraction::operator-() const
{
	return Fraction(-this->_num, this->_den);
}

// Comparison operators
bool Fraction::operator==(const Fraction& rhs) const
{
	return this->_num == rhs._num && this->_den == rhs._den;
}
bool Fraction::operator!=(const Fraction& rhs) const
{
	return !(*this == rhs);
}

// Compound assignment operators
// Compound add: Adds b to a
Fraction& Fraction::operator+=(const Fraction& rhs)
{
	this->_num = this->_num * rhs._den + this->_den * rhs._num;
	this->_den = this->_den * rhs._den;
	normalize();
	return *this;
}

// Compound sub: Subtract b from a
Fraction& Fraction::operator-=(const Fraction& rhs)
{
	return (*this += rhs.operator-());
}

// Compound mul: Multiply b into a
Fraction& Fraction::operator*=(const Fraction& rhs)
{
	this->_num *= rhs._num;
	this->_den *= rhs._den;
	normalize();
	return *this;
}

// Compound div: Divide b from a
// No div by 0 checking is done here, do it yourself!
Fraction& Fraction::operator/=(const Fraction& rhs)
{
	return (*this *= rhs.inverse());
}

// Binary operators
const Fraction Fraction::operator+(const Fraction& rhs) const
{
	return (Fraction(*this) += rhs);
}
const Fraction Fraction::operator-(const Fraction& rhs) const
{
	return (Fraction(*this) -= rhs);
}
const Fraction Fraction::operator*(const Fraction& rhs) const
{
	return (Fraction(*this) *= rhs);
}
const Fraction Fraction::operator/(const Fraction& rhs) const
{
	return (Fraction(*this) /= rhs);
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Fraction& frac)
{
	if (std::abs(frac._num) % frac._den == 0)
		os << frac._num / frac._den;
	else
		os << frac._num << '/' << frac._den;
	return os;
}
