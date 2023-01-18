// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 283. Move Zeroes

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    vector<int> res(r + 1);

    for (auto num : nums)
    {
        if (num == 0)
            res[r--] = num;
        else
            res[l++] = num;
    }

    nums = res;
}

int main()
{
    vector<int> nums{0, 1, 0, 2, 3, 4};
    moveZeroes(nums);
    return 0;
}