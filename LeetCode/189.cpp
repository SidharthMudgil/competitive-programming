// USER: SIDHARTH MUDGIL
// DATE: Tuesday 17, Jan 2023
// TASK: 189. Rotated Array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    rotate(v, 3);

    return 0;
}