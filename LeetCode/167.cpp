// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 167. Two Sum II - Input Array Is Sorted

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r)
    {
        if (numbers[l] + numbers[r] == target)
            return {l + 1, r + 1};
        else if (numbers[l] + numbers[r] > target)
            r--;
        else
            l++;
    }
    return {l + 1, r + 1};
}

int main()
{
    vector<int> nums{1, 3, 4, 5};
    cout << twoSum(nums, 9);
    return 0;
}