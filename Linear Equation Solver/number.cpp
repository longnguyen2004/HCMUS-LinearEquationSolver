#include "number.h"

// Solve Ax + B = Cx + D, with the coefficients as numbers
int solve_eq_number(double& x, double a, double b, double c, double d)
{
	// 1. Rearrange: (A - C)x = D - B
	a = a - c;
	b = d - b;

	// 2. Special case: A == 0
	if (a == 0)
	{
		// 2.1 B == 0 => Infinite solutions
		if (b == 0) return -1;

		// 2.2 B != 0 => No solutions
		else return 0;
	}
	else
	{
		// 2.3 x = (D - B)/(A - C)
		x = b / a;

		// Check for negative zeroes
		if (x == -0.0)
			x = 0.0;
		return 1;
	}
}
