#include "gmath/gmath.hpp"
#include <iostream>


int main()
{
	gmath::matrix4<int> a(
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16});

    gmath::matrix4<int> b(
    {21, 22, 23, 24},
    {25, 26, 27, 28},
    {29, 30, 31, 32},
    {33, 34, 35, 36});

    gmath::matrix4<int> c = a * b;

    std::cout << "result of multiplication\n";
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << "\n";
    }
	return 0;
}