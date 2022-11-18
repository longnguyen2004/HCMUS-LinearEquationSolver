#include "fraction.h"
#include <cmath>
using namespace std;

int fGCD(int a, int b) {
	if (a == b || b == 0) return a;
	else return fGCD(b, a % b);
}
void simplify(int& numV, int& denV) {
	int GCD = fGCD(abs(numV), abs(denV));
	if (denV < 0) {
		numV /= -1;
		denV /= -1;
	}
	numV /= GCD;
	denV /= GCD;
}

int solve_eq_fraction(int& numV, int& denV, int numA, int denA, int numB, int denB, int numC, int denC, int numD, int denD){
	numA = numA * denC - numC * denA;
	denA = denA * denC;
	numB = numB * denD - numD * denB;
	denB = denB * denD;
	if (!numA) {
		if (!numB) return -1;
		else return 0;
	}
	else {
		if (!numB) {
			numV = 0;
			denV = 1;
		}
		else {
			numV = -(numB * denA);
			denV = (denB * numA);
			simplify(numV, denV);
		}
		return 1;
	}
}