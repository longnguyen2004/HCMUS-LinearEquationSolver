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

void write_complex(double real, double imag)
{
	std::cout << real;
	if (imag != 0)
	{
		if (imag > 0) std::cout << '+';
		std::cout << imag << 'i';
	}
}
