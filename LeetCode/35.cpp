// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 35. Search Insert Position

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    vector<int> nums{1, 2, 4, 5, 6, 8};
    cout << searchInsert(nums, 7);
    return 0;
}