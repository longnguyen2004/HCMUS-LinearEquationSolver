#pragma once
class Fraction
{
public:
	Fraction(long long num = 0, long long den = 1);
	long long num() const;
	long long den() const;
	Fraction inverse() const;
	Fraction operator-() const;
	bool operator==(const Fraction& rhs) const;
	bool operator!=(const Fraction& rhs) const;
	Fraction& operator+=(const Fraction& rhs);
	Fraction& operator-=(const Fraction& rhs);
	Fraction& operator*=(const Fraction& rhs);
	Fraction& operator/=(const Fraction& rhs);
	const Fraction operator+(const Fraction& rhs) const;
	const Fraction operator-(const Fraction& rhs) const;
	const Fraction operator*(const Fraction& rhs) const;
	const Fraction operator/(const Fraction& rhs) const;
	friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};
