// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 724. Find Pivot Index

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    int i = 0;
    int l_sum = 0;
    int t_sum = accumulate(nums.begin(), nums.end(), 0);

    while (i < nums.size())
    {
        int r_sum = t_sum - l_sum - nums[i];
        if (l_sum == r_sum)
            return i;
        l_sum += nums[i++];
    }

    return -1;
}

int main()
{
    vector<int> nums{1, 2, 3, 6, 4, 5};
    cout << pivotIndex(nums);
    return 0;
}