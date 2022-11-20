#include "fraction.h"
#include <cmath>
using namespace std;

int fGCD(int a, int b) {
	if (a == b || b == 0) return a;
	else return fGCD(b, a % b);
}

// Simplify the fraction
void simplify(int& numV, int& denV) {
	int GCD = fGCD(abs(numV), abs(denV));
	if (denV < 0) {
		numV /= -1;
		denV /= -1;
	}
	numV /= GCD;
	denV /= GCD;
}

// Calculate a/b + c/d
void fraction_add(int& num, int& den, int a, int b, int c, int d)
{
	den = b * d;
	num = a * d + b * c;
	simplify(num, den);
}

// Calculate a/b - c/d
void fraction_sub(int& num, int& den, int a, int b, int c, int d)
{
	fraction_add(num, den, a, b, -c, d);
}

// Calculate a/b * c/d
void fraction_mul(int& num, int& den, int a, int b, int c, int d)
{
	num = a * c;
	den = b * d;
	simplify(num, den);
}

// Calculate a/b / c/d
bool fraction_div(int& num, int& den, int a, int b, int c, int d)
{
	if (c == 0) return false;
	fraction_mul(num, den, a, b, d, c);
	return true;
}

// Solve Ax + B = Cx + D, with the coefficients as fractions
int solve_eq_fraction(int& numX, int& denX, int numA, int denA, int numB, int denB, int numC, int denC, int numD, int denD)
{
	// 1. Rearrange: (A - C)x = D - B
	fraction_sub(numA, denA, numA, denA, numC, denC);
	fraction_sub(numB, denB, numD, denD, numB, denB);

	// 2. Special case: A == 0
	if (!numA) {
		// 2.1 B == 0 => Infinite solutions
		if (!numB) return -1;

		// 2.2 B != 0 => No solutions
		else return 0;
	}
	else {
		// 2.3 x = (D - B)/(A - C)
		fraction_div(numX, denX, numB, denB, numA, denA);
		return 1;
	}
}