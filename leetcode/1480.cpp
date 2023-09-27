// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 1480. Running Sum of 1D Array

#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    vector<int> sums = {};
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
        sums.push_back(sum);
    }
    return sums;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    vector<int> res = runningSum(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}