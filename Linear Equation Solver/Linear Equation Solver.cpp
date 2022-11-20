// Linear Equation Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "reader.h"
#include "writer.h"
#include "fraction.h"
#include "complex.h"
#include "solver.h"

int main()
{
    int eq_type;
    std::cout
        << "GIẢI PHƯƠNG TRÌNH BẬC NHẤT\n"
        << '\n'
        << "Chọn kiểu phương trình: \n"
        << "1. Ax + B = 0\n"
        << "2. Ax + B = Cx + D\n"
        << '\n';
    while (true)
    {
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> eq_type;
        if (eq_type == 1 || eq_type == 2) break;
        std::cout << "Vui lòng chọn lại!\n";
        std::cout << '\n';
    }
    std::cout << '\n';

    int num_type;
    std::cout
        << "Chọn kiểu số: \n"
        << "1. Số thực\n"
        << "2. Phân số\n"
        << "3. Số phức\n"
        << '\n';
    while (true)
    {
        std::cout << "Lựa chọn của bạn: ";
        std::cin >> num_type;
        if (num_type >= 1 && num_type <= 3) break;
        std::cout << "Vui lòng chọn lại!\n";
        std::cout << '\n';
    }
    std::cout << '\n';

    int status = 0;
    switch (num_type)
    {
    case 1:
    {
        double a, b, c = 0, d = 0;
        if (eq_type == 1)
            read_eq_number_type1(a, b);
        else
            read_eq_number_type2(a, b, c, d);
        double x;
        status = solve_eq(x, a, b, c, d);
        if (status == 1)
        {
            if (x == -0.0) x = 0.0;
            std::cout << "Phương trình có 1 nghiệm: " << x << '\n';
        }
        break;
    }
    case 2:
    {
        Fraction a, b, c, d, x;
        if (eq_type == 1)
            read_eq_fraction_type1(a, b);
        else
            read_eq_fraction_type2(a, b, c, d);
        status = solve_eq(x, a, b, c, d);
        if (status == 1)
            std::cout << "Phương trình có 1 nghiệm: " << x << '\n';
        break;
    }
    case 3:
    {
        Complex a, b, c, d, x;
        if (eq_type == 1)
            read_eq_complex_type1(a, b);
        else
            read_eq_complex_type2(a, b, c, d);
        status = solve_eq(x, a, b, c, d);
        if (status == 1)
            std::cout << "Phương trình có 1 nghiệm: " << x << '\n';
        break;
    }
    }
    if (status == -1)
        std::cout << "Phương trình có vô số nghiệm\n";
    else if (status == 0)
        std::cout << "Phương trình vô nghiệm\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
