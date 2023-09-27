// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 278. First Bad Version

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n)
{
    long long l = 0;
    long long h = n;
    while (l <= h)
    {
        long long m = (l + h) / 2;
        if (isBadVersion(m) && !isBadVersion(m - 1))
            return m;
        else if (!isBadVersion(m))
            l = m + 1;
        else
            h = m - 1;
    }

    return 0;
}

int main()
{
    cout << firstBadVersion(5);
    return 0;
}