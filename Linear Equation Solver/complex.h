#pragma once
class Complex
{
public:
	Complex(double real = 0, double imag = 0);
	double real() const;
	double imag() const;
	Complex operator-() const;
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;
	Complex& operator+=(const Complex& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator/=(const Complex& rhs);
	const Complex operator+(const Complex& rhs) const;
	const Complex operator-(const Complex& rhs) const;
	const Complex operator*(const Complex& rhs) const;
	const Complex operator/(const Complex& rhs) const;
	friend std::ostream& operator<<(std::ostream& os, const Complex& comp);
};
