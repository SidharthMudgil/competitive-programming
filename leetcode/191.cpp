// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 191. Number of 1 Bits

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int hammingWeight(uint32_t n)
{
    int cnt = 0;
    while (n)
    {
        n &= n - 1;
        cnt++;
    }
    return cnt;
}

int main()
{
    cout << hammingWeight('1000111101111');
    return 0;
}