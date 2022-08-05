#include <iostream>
#include <map>

long long int fibo(int n, std::map<int, long long int> &memo)
{
    if (memo[n])
        return memo[n];
    if (n <= 2)
        return 1;
    memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
    return memo[n];
}

int main()
{
    std::map<int, long long int> memo;
    std::cout << fibo(50, memo);
    return 0;
}