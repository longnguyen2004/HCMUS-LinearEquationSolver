#include "complex.h"

// Calculate (a + bi) + (c + di)
void complex_add(double& real, double& imag, double a, double b, double c, double d)
{
	real = a + c;
	imag = b + d;
}

// Calculate (a + bi) - (c + di)
void complex_sub(double& real, double& imag, double a, double b, double c, double d)
{
	real = a - c;
	imag = b - d;
}

// Calculate (a + bi) * (c + di)
void complex_mul(double& real, double& imag, double a, double b, double c, double d)
{
	real = a * c - b * d;
	imag = a * d + b * c;
}

// Calculate (a + bi) / (c + di)
bool complex_div(double& real, double& imag, double a, double b, double c, double d)
{
	if (c == 0 && d == 0) return false;
	double den = c * c + d * d;
	real = (a * c + b * d) / den;
	imag = (b * c - a * d) / den;
}

// Solve Ax + B = Cx + D, with the coefficients as complex numbers
int solve_eq_complex(double& realV, double& imagV,
	double realA, double imagA, double realB, double imagB,
	double realC, double imagC, double realD, double imagD
)
{
	// 1. Rearrange: (A - C)x = D - B
	complex_sub(realA, imagA, realA, imagA, realC, imagC);
	complex_sub(realB, imagB, realD, imagD, realB, imagB);

	// 2. Special case: A = 0
	if (realA == 0 && imagA == 0)
	{
		// 2.1 Both coefficients are 0 => Infinite solutions
		if (realB == 0 && imagB == 0) return -1;

		// 2.2 Else: No solutions
		else return 0;
	}
	else
	{
		// 2.3: x = (D - B)/(A - C)
		complex_div(realV, imagV, realB, imagB, realA, imagA);
		return 0;
	}
}
