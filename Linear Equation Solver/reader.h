#pragma once
#include "complex.h"

void read_eq_number_type1(double& a, double& b, char name1 = 'A', char name2 = 'B');
void read_eq_number_type2(double& a, double& b, double& c, double& d);
void read_eq_fraction_type1(int& numA, int& denA, int& numB, int& denB, char name1 = 'A', char name2 = 'B');
void read_eq_fraction_type2(
	int& numA, int& denA, int& numB, int& denB,
	int& numC, int& denC, int& numD, int& denD
);
void read_eq_complex_type1(Complex& a, Complex& b, char name1 = 'A', char name2 = 'B');
void read_eq_complex_type2(Complex& a, Complex& b, Complex& c, Complex& d);