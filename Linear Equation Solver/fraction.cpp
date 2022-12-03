#include "fraction.h"
#include <cmath>
#include <algorithm>

int fGCD(int a, int b) {
	if (a == b || b == 0) return a;
	else return fGCD(b, a % b);
}

// Simplify the fraction
void simplify(Fraction& frac) {
	int GCD = fGCD(std::abs(frac.num), std::abs(frac.den));
	if (frac.den < 0) {
		frac.num /= -1;
		frac.den /= -1;
	}
	frac.num /= GCD;
	frac.den /= GCD;
}

// Calculate a/b + c/d
Fraction fraction_add(Fraction a, Fraction b)
{
	Fraction result = { a.num * b.den + a.den * b.num, a.den * b.den };
	simplify(result);
	return result;
}

// Calculate a/b - c/d
Fraction fraction_sub(Fraction a, Fraction b)
{
	b.num = -b.num;
	return fraction_add(a, b);
}

// Calculate a/b * c/d
Fraction fraction_mul(Fraction a, Fraction b)
{
	Fraction result = { a.num * b.num, a.den * b.den };
	simplify(result);
	return result;
}

// Calculate a/b / c/d
Fraction fraction_div(Fraction a, Fraction b)
{
	std::swap(b.num, b.den);
	return fraction_mul(a, b);
}

// Solve Ax + B = Cx + D, with the coefficients as fractions
int solve_eq_fraction(Fraction& result, Fraction a, Fraction b, Fraction c, Fraction d)
{
	// 1. Rearrange: (A - C)x = D - B
	a = fraction_sub(a, c);
	b = fraction_sub(d, b);

	// 2. Special case: A == 0
	if (!a.num) {
		// 2.1 B == 0 => Infinite solutions
		if (!a.den) return -1;

		// 2.2 B != 0 => No solutions
		else return 0;
	}
	else {
		// 2.3 x = (D - B)/(A - C)
		result = fraction_div(b, a);
		return 1;
	}
}