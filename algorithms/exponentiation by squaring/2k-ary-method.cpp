#include <iostream>
#define MOD 1000000007;

long long int fast_exp(int k, int n)
{
    long long int res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            res = res * k;
        k = k * k;
        n /= 2;
    }
    return res % MOD;
}

int main()
{
    std::cout << fast_exp(2, 20);
    return 0;
}