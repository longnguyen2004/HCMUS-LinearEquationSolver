#pragma once

// Solve Ax + B = Cx + D for any data types
template <typename T>
int solve_eq(T& x, T a, T b, T c, T d)
{
	// 1. Rearrange: (A - C)x + B - D = 0;
	a -= c;
	b -= d;

	// 2. Special case: A == 0
	if (a == 0)
	{
		// 2.1. B == 0 => Infinite solutions, else no solutions
		return b == 0 ? -1 : 0;
	}
	else
	{
		x = -b / a;
		return 1;
	}
}
