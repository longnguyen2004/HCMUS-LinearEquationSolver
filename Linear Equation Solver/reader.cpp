#include "reader.h"
#include <iostream>

Fraction read_fraction()
{
	long long num, den;
	std::cout << "Nhập tử số: ";
	std::cin >> num;
	do
	{
		std::cout << "Nhập mẫu số (khác 0): ";
		std::cin >> den;
	} while (den == 0);
	return Fraction(num, den);
}
Complex read_complex()
{
	double real, imag;
	std::cout << "Nhập phần thực: ";
	std::cin >> real;
	std::cout << "Nhập phần ảo: ";
	std::cin >> imag;
	return Complex(real, imag);
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
void read_eq_fraction_type1(Fraction& a, Fraction& b, char name1, char name2)
{
	std::cout << "Nhập hệ số " << name1 << '\n';
	a = read_fraction();
	std::cout << '\n';
	std::cout << "Nhập hệ số " << name2 << '\n';
	b = read_fraction();
	std::cout << '\n';
}
void read_eq_fraction_type2(Fraction& a, Fraction& b, Fraction& c, Fraction& d)
{
	read_eq_fraction_type1(a, b);
	read_eq_fraction_type1(c, d, 'C', 'D');
}
void read_eq_complex_type1(Complex& a, Complex& b, char name1, char name2)
{
	std::cout << "Nhập hệ số " << name1 << '\n';
	a = read_complex();
	std::cout << '\n';
	std::cout << "Nhập hệ số " << name2 << '\n';
	b = read_complex();
	std::cout << '\n';
}
void read_eq_complex_type2(Complex& a, Complex& b, Complex& c, Complex& d)
{
	read_eq_complex_type1(a, b);
	read_eq_complex_type1(c, d, 'C', 'D');
}
