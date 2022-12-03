#include "complex.h"

// Calculate (a + bi) + (c + di)
void complex_add(Complex& result, Complex a, Complex b)
{
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
}

// Calculate (a + bi) - (c + di)
void complex_sub(Complex& result, Complex a, Complex b)
{
	b.real = -b.real;
	b.imag = -b.imag;
	complex_add(result, a, b);
}

// Calculate (a + bi) * (c + di)
void complex_mul(Complex& result, Complex a, Complex b)
{
	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
}

// Calculate (a + bi) / (c + di)
bool complex_div(Complex& result, Complex a, Complex b)
{
	if (b.real == 0 && b.imag == 0) return false;
	double den = b.real * b.real + b.imag * b.imag;
	result.real = (a.real * b.real + a.imag * b.imag) / den;
	result.imag = (a.imag * b.real - a.real * b.imag) / den;
	return true;
}

// Solve Ax + B = Cx + D, with the coefficients as complex numbers
int solve_eq_complex(Complex& result, Complex a, Complex b, Complex c, Complex d)
{
	// 1. Rearrange: (A - C)x = D - B
	complex_sub(a, a, c);
	complex_sub(b, d, b);

	// 2. Special case: A == 0
	if (a.real == 0 && a.imag == 0)
	{
		// 2.1 B == 0 => Infinite solutions
		if (b.real == 0 && b.imag == 0) return -1;

		// 2.2 B != 0 => No solutions
		else return 0;
	}
	else
	{
		// 2.3: x = (D - B)/(A - C)
		complex_div(result, b, a);
		return 1;
	}
}
