#include "fraction.h"
#include <cmath>
#include <iostream>

long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

class Fraction
{
private:
	long long _num, _den;
	void normalize()
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

public:
	Fraction(long long num, long long den) : _num(num), _den(den)
	{
		this->normalize();
	}

	// Returns the numerator and denominator
	long long num() const { return _num; }
	long long den() const { return _den; }

	// Returns the inverse fraction
	Fraction inverse() const
	{
		return Fraction(this->_den, this->_num);
	}

	// Unary minus: Returns -a
	Fraction operator-() const
	{
		return Fraction(-this->_num, this->_den);
	}

	// Comparison operators
	bool operator==(const Fraction& rhs) const
	{
		return this->_num == rhs._num && this->_den == rhs._den;
	}
	bool operator!=(const Fraction& rhs) const
	{
		return !(*this == rhs);
	}

	// Compound assignment operators
	// Compound add: Adds b to a
	Fraction& operator+=(const Fraction& rhs)
	{
		this->_num = this->_num * rhs._den + this->_den * rhs._num;
		this->_den = this->_den * rhs._den;
		normalize();
		return *this;
	}

	// Compound sub: Subtract b from a
	Fraction& operator-=(const Fraction& rhs)
	{
		return (*this += -rhs);
	}

	// Compound mul: Multiply b into a
	Fraction& operator*=(const Fraction& rhs)
	{
		this->_num *= rhs._num;
		this->_den *= rhs._den;
		normalize();
		return *this;
	}

	// Compound div: Divide b from a
	// No div by 0 checking is done here, do it yourself!
	Fraction& operator/=(const Fraction& rhs)
	{
		return (*this *= rhs.inverse());
	}

	// Binary operators
	const Fraction operator+(const Fraction& rhs) const
	{
		return (Fraction(*this) += rhs);
	}
	const Fraction operator-(const Fraction& rhs) const
	{
		return (Fraction(*this) -= rhs);
	}
	const Fraction operator*(const Fraction& rhs) const
	{
		return (Fraction(*this) *= rhs);
	}
	const Fraction operator/(const Fraction& rhs) const
	{
		return (Fraction(*this) /= rhs);
	}

	// Output stream operator
	friend std::ostream& operator<<(std::ostream& os, const Fraction& frac)
	{
		if (std::abs(frac._num) % frac._den == 0)
			os << frac._num / frac._den;
		else
			os << frac._num << '/' << frac._den;
	}
};
