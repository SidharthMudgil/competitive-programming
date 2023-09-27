// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Jan 2023
// TASK: 1588. Sum of All Odd Length Subarrays

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int sumOddLengthSubarrays(vector<int> &arr)
{
    int res = 0;

    for (int i = 0; i < arr.size(); i++)
        for (int j = i; j < arr.size(); j += 2)
            res += accumulate(arr.begin() + i, arr.begin() + j + 1, 0);

    return res;
}

int main()
{
    vector<int> v{24, 3, 2, 4, 5, 3, 2};
    cout << sumOddLengthSubarrays(v);
    return 0;
}