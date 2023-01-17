// USER: SIDHARTH MUDGIL
// DATE: Tuesday 17, Jan 2023
// TASK: 977. Squares of a Sorted Array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// vector<int> sortedSquares(vector<int> &nums)
// {
//     vector<int> result;

//     for (auto num : nums)
//         result.push_back(num * num);

//     sort(result.begin(), result.end());

//     return result;
// }

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> result(nums.size());
    int l = 0;
    int r = nums.size() - 1;

    for (int k = nums.size() - 1; k >= 0; k--)
    {
        result[k] = abs(nums[l]) > abs(nums[r]) ? nums[l] * nums[l++] : nums[r] * nums[r--];
    }

    return result;
}

int main()
{
    vector<int> v{-4, -1, 0, 1, 2, 3};
    vector<int> res = sortedSquares(v);
    for (auto x : res)
        cout << x << " ";
    return 0;
}