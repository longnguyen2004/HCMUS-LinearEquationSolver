#include "writer.h"
#include <iostream>
#include <cmath>

void write_fraction(Fraction a)
{
	if (abs(a.num) % a.den == 0)
		std::cout << a.num / a.den;
	else
		std::cout << a.num << '/' << a.den;
}

void write_complex(Complex a)
{
	std::cout << a.real;
	if (a.imag != 0)
	{
		if (a.imag > 0) std::cout << '+';
		std::cout << a.imag << 'i';
	}
}
