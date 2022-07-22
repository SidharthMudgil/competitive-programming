#include <iostream>

int euclidean_gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    bool a_greater = a > b;

    if (a_greater)
        return euclidean_gcd(b, a % b);
    else
        return euclidean_gcd(a, b % a);
}

int main()
{
    std::cout << euclidean_gcd(25, 36);
    return 0;
}