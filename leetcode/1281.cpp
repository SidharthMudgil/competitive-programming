// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 1281. Subtract the Product and Sum of Digits of an Integer

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int subtractProductAndSum(int n)
{
    int sum = 0;
    int mul = 1;

    while (n)
    {
        int rem = n % 10;
        n = n / 10;
        sum += rem;
        mul *= rem;
    }

    return mul - sum;
}

int main()
{
    cout << subtractProductAndSum(102);
    return 0;
}