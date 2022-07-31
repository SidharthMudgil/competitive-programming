#include <iostream>
#include <math.h>

int size_base10(int num)
{
    int digits = 0;

    while (num > 0)
    {
        num /= 10;
        digits++;
    }

    return digits;
}

std::pair<int, int> split_at(int num, int pos)
{
    std::cout << pos << "\n";
    int Bm = pow(10, pos);
    return std::make_pair(num / Bm, num % Bm);
}

long long int karatsuba(int num1, int num2)
{
    if (num1 < 10 || num2 < 10)
        return num1 * num2;

    int m = ((num1 > num2) ? size_base10(num2) : size_base10(num1));
    m /= 2;

    std::pair<int, int> x = split_at(num1, m);
    std::pair<int, int> y = split_at(num2, m);

    int z0 = karatsuba(x.second, y.second);
    int z2 = karatsuba(x.first, y.first);
    int z1 = karatsuba(x.first + x.second, y.first + y.second) - z2 - z0;

    //  result = z2 · (Bm)^2 + z1 · (Bm)^1 + z0 · (Bm)^0
    return z2 * pow(10, m * 2) + z1 * pow(10, m) + z0;
}

int main()
{
    std::cout << karatsuba(5121221, 212122);
    return 0;
}