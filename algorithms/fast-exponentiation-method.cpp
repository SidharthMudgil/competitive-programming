#include <iostream>

long long int fast_exp(int k, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return k;
    else
    {
        if (n % 2 == 0)
        {
            long long int k1 = fast_exp(k * k, n / 2);
            return k1 % 1000000007;
        }
        else
        {
            long long int k1 = k * fast_exp(k * k, (n - 1) / 2);
            return k1 % 1000000007;
        }
    }
}

int main()
{
    std::cout << fast_exp(2, -9);
    return 0;
}