// USER: SIDHARTH MUDGIL
// DATE: Thursday 19, Jan 2023
// TASK: 976. Largest Perimeter Triangle

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 3; i >= 0; i--)
    {
        if (nums[i] + nums[i + 1] > nums[i + 2])
            return nums[i] + nums[i + 1] + nums[i + 2];
    }
    return 0;
}

int main()
{
    vector<int> nums{1, 2, 20, 32, 12};
    cout << largestPerimeter(nums);
    return 0;
}