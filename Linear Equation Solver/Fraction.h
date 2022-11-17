#pragma once
struct Fraction
{
	Fraction(int num = 0, int den = 1);
	void normalize();
	Fraction operator+(const Fraction& rhs);
	Fraction operator-(const Fraction& rhs);
	Fraction operator*(const Fraction& rhs);
	Fraction operator/(const Fraction& rhs);
};