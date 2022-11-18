#include "writer.h"
#include <iostream>

void write_fraction(int num, int den)
{
	std::cout << num;
	if (den != 1)
		std::cout << '/' << den;
}

void write_complex(double real, double imag)
{
	std::cout << real;
	if (imag != 0)
		std::cout << " + " << imag << 'i';
}
