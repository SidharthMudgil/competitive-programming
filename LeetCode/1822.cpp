// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Jan 2023
// TASK: 1822. Sign of the Product of an Array

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arraySign(vector<int> &nums)
{
    int res = 0;

    for (auto num : nums)
    {
        if (num == 0)
            return 0;

        if (num < 0)
            res++;
    }

    return res % 2 == 0 ? 1 : -1;
}

int main()
{
    vector<int> r{1, 3, 5, 6, 6};
    cout << arraySign(r);
    return 0;
}