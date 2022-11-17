// Linear Equation Solver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "reader.h"

int main()
{
    int eq_type;
    std::cout
        << "GIẢI PHƯƠNG TRÌNH BẬC NHẤT\n"
        << "Chọn kiểu phương trình: \n"
        << "1. Ax + B = 0\n"
        << "2. Ax + B = Cx + D\n"
        << '\n'
        << "Lựa chọn của bạn: ";
    std::cin >> eq_type;
    std::cout << '\n';

    int num_type;
    std::cout
        << "Chọn kiểu số: \n"
        << "1. Số thực\n"
        << "2. Phân số\n"
        << "3. Số phức\n"
        << '\n'
        << "Lựa chọn của bạn: ";
    std::cin >> num_type;
    std::cout << '\n';

    switch (num_type)
    {
    case 1:
    {
        double a, b, c = 0, d = 0;
        if (eq_type == 1)
            read_eq_number_type1(a, b);
        else
            read_eq_number_type2(a, b, c, d);
        break;
    }
    case 2:
    {
        int numA, denA, numB, denB, numC = 0, denC = 1, numD = 0, denD = 1;
        if (eq_type == 1)
            read_eq_fraction_type1(numA, denA, numB, denB);
        else
            read_eq_fraction_type2(numA, denA, numB, denB, numC, denC, numD, denD);
        break;
    }
    case 3:
    {
        double realA, imagA, realB, imagB, realC = 0, imagC = 0, realD = 0, imagD = 0;
        if (eq_type == 1)
            read_eq_complex_type1(realA, imagA, realB, imagB);
        else
            read_eq_complex_type2(realA, imagA, realB, imagB, realC, imagC, realD, imagD);
        break;
    }
    }

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
