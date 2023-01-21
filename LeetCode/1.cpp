// USER: SIDHARTH MUDGIL
// DATE: Thursday 19, Jan 2023
// TASK: 1. Two Sum

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int i;
    map<int, int> res;

    for (i = 0; i < nums.size(); i++)
    {
        if (res.find(target - nums[i]) != res.end())
            break;
        res[nums[i]] = i;
    }

    return {res[target - nums[i]], i};
}

int main()
{
    vector<int> nums{1, 2, 4, 6, 7};
    vector<int> res = twoSum(nums, 5);
    return 0;
}