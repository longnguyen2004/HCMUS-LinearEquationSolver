#pragma once
#include "fraction.h"
#include "complex.h"

Fraction read_fraction();
Complex read_complex();

void read_eq_number_type1(double& a, double& b, char name1 = 'A', char name2 = 'B');
void read_eq_number_type2(double& a, double& b, double& c, double& d);
void read_eq_fraction_type1(Fraction& a, Fraction& b, char name1 = 'A', char name2 = 'B');
void read_eq_fraction_type2(Fraction& a, Fraction& b, Fraction& c, Fraction& d);
void read_eq_complex_type1(Complex& a, Complex& b, char name1 = 'A', char name2 = 'B');
void read_eq_complex_type2(Complex& a, Complex& b, Complex& c, Complex& d);