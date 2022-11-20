#pragma once
#include "fraction.h"

Fraction read_fraction();
void read_complex(double& real, double& imag);

void read_eq_number_type1(double& a, double& b, char name1 = 'A', char name2 = 'B');
void read_eq_number_type2(double& a, double& b, double& c, double& d);
void read_eq_fraction_type1(Fraction& a, Fraction& b, char name1 = 'A', char name2 = 'B');
void read_eq_fraction_type2(Fraction& a, Fraction& b, Fraction& c, Fraction& d);
void read_eq_complex_type1(double& realA, double& imagA, double& realB, double& imagB, char name1 = 'A', char name2 = 'B');
void read_eq_complex_type2(
	double& realA, double& imagA, double& realB, double& imagB,
	double& realC, double& imagC, double& realD, double& imagD
);