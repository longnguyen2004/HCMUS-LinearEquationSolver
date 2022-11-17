#pragma once
struct Complex
{
	Complex(double real = 0, double imag = 0);
	Complex operator+(const Complex& rhs);
	Complex operator-(const Complex& rhs);
	Complex operator*(const Complex& rhs);
	Complex operator/(const Complex& rhs);
};