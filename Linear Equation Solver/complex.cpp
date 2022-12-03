#include "complex.h"

// Calculate (a + bi) + (c + di)
Complex complex_add(Complex a, Complex b)
{
	return { a.real + b.real, a.imag + b.imag };
}

// Calculate (a + bi) - (c + di)
Complex complex_sub(Complex a, Complex b)
{
	b.real = -b.real;
	b.imag = -b.imag;
	return complex_add(a, b);
}

// Calculate (a + bi) * (c + di)
Complex complex_mul(Complex& result, Complex a, Complex b)
{
	return { a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real };
}

// Calculate (a + bi) / (c + di)
Complex complex_div(Complex a, Complex b)
{
	double den = b.real * b.real + b.imag * b.imag;
	return { (a.real * b.real + a.imag * b.imag) / den, (a.imag * b.real - a.real * b.imag) / den };
}

// Solve Ax + B = Cx + D, with the coefficients as complex numbers
int solve_eq_complex(Complex& result, Complex a, Complex b, Complex c, Complex d)
{
	// 1. Rearrange: (A - C)x = D - B
	a = complex_sub(a, c);
	b = complex_sub(d, b);

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
		result = complex_div(b, a);
		return 1;
	}
}
