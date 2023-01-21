// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Jan 2023
// TASK: 202. Happy Number

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isHappy(int n)
{
    map<int, int> m;

    while (m[n] != 1)
    {
        if (n == 1)
            return true;

        m[n] = 1;

        int t = 0;
        while (n > 0)
        {
            int r = n % 10;
            t += r * r;
            n /= 10;
        }

        n = t;
    }

    return false;
}

int main()
{
    cout << isHappy(56);
    return 0;
}