// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 704. Binary Search

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << low << " " << mid << " " << high << endl;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int> vec{1, 2, 4, 5, 7, 9, 7, 5, 4};
    cout << search(vec, 9);
    return 0;
}