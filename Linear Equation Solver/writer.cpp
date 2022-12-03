#include "writer.h"
#include <iostream>
#include <cmath>

void write_fraction(int num, int den)
{
	if (abs(num) % den == 0)
		std::cout << num / den;
	else
		std::cout << num << '/' << den;
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
