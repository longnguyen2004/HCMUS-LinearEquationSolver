#include "complex.h"
#include <iostream>
#include <iomanip>

Complex::Complex(double real, double imag) : _real(real), _imag(imag)
{

}
double Complex::real() const { return _real; }
double Complex::imag() const { return _imag; }
Complex Complex::operator-() const
{
	return Complex(-this->_real, -this->_imag);
}
bool Complex::operator==(const Complex& rhs) const
{
	return this->_real == rhs._real && this->_imag == rhs._imag;
}
bool Complex::operator!=(const Complex& rhs) const
{
	return !(*this == rhs);
}
Complex& Complex::operator+=(const Complex& rhs)
{
	this->_real += rhs._real;
	this->_imag += rhs._imag;
	return *this;
}
Complex& Complex::operator-=(const Complex& rhs)
{
	return (*this += rhs.operator-());
}
Complex& Complex::operator*=(const Complex& rhs)
{
	this->_real = this->_real * rhs._real - this->_imag * rhs._imag;
	this->_imag = this->_real * rhs._imag + this->_imag * rhs._real;
	return *this;
}
Complex& Complex::operator/=(const Complex& rhs)
{
	double a = this->_real, b = this->_imag, c = rhs._real, d = rhs._imag;
	double den = c * c + d * d;
	this->_real = (a * c + b * d) / den;
	this->_imag = (b * c - a * d) / den;
	return *this;
}
const Complex Complex::operator+(const Complex& rhs) const
{
	return (Complex(*this) += rhs);
}
const Complex Complex::operator-(const Complex& rhs) const
{
	return (Complex(*this) -= rhs);
}
const Complex Complex::operator*(const Complex& rhs) const
{
	return (Complex(*this) *= rhs);
}
const Complex Complex::operator/(const Complex& rhs) const
{
	return (Complex(*this) /= rhs);
}
std::ostream& operator<<(std::ostream& os, const Complex& comp)
{
	auto flags = os.flags();
	os << comp._real;
	if (comp._imag != 0)
		os << ' ' << std::showpos << comp._imag << 'i';
	os.flags(flags);
	return os;
}
