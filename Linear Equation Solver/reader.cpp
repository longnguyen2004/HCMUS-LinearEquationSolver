#pragma once
#include "reader.h"
#include <iostream>

void read_fraction(int& num, int& den)
{
	std::cout << "Nhập tử số: ";
	std::cin >> num;
	do
	{
		std::cout << "Nhập mẫu số: ";
		std::cin >> den;
	} while (den == 0);
}
void read_complex(double& real, double& imag)
{
	std::cout << "Nhập phần thực: ";
	std::cin >> real;
	std::cout << "Nhập phần ảo: ";
	std::cin >> imag;
}

void read_eq_number_type1(double& a, double& b, char name1, char name2)
{
	std::cout << "Nhập hệ số " << name1 << ": ";
	std::cin >> a;
	std::cout << "Nhập hệ số " << name2 << ": ";
	std::cin >> b;
}
void read_eq_number_type2(double& a, double& b, double& c, double& d)
{
	read_eq_number_type1(a, b);
	read_eq_number_type1(c, d, 'C', 'D');
}
void read_eq_fraction_type1(int& numA, int& denA, int& numB, int& denB, char name1, char name2)
{
	std::cout << "Nhập hệ số " << name1 << '\n';
	read_fraction(numA, denA);
	std::cout << "Nhập hệ số " << name2 << '\n';
	read_fraction(numB, denB);
}
void read_eq_fraction_type2(int& numA, int& denA, int& numB, int& denB, int& numC, int& denC, int& numD, int& denD)
{
	read_eq_fraction_type1(numA, denA, numB, denB);
	read_eq_fraction_type1(numC, denC, numD, denD, 'C', 'D');
}
void read_eq_complex_type1(double& realA, double& imagA, double& realB, double& imagB, char name1, char name2)
{
	std::cout << "Nhập hệ số " << name1 << '\n';
	read_complex(realA, imagA);
	std::cout << "Nhập hệ số " << name2 << '\n';
	read_complex(realB, imagB);
}
void read_eq_complex_type2(double& realA, double& imagA, double& realB, double& imagB, double& realC, double& imagC, double& realD, double& imagD)
{
	read_eq_complex_type1(realA, imagA, realB, imagB);
	read_eq_complex_type1(realC, imagC, realD, imagD, 'C', 'D');
}
