// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Jan 2023
// TASK: 974. Subarray Sums Divisible by K

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum = 0, result = 0;

    vector<int> rem(k, 0);
    rem[0] = 1;

    for (int num : nums)
    {
        sum += num;
        int r = (sum % k) < 0 ? sum % k + k : sum % k;
        result += rem[r];
        rem[r]++;
    }

    return result;
}

int main()
{
    vector<int> nums{1, 2, 4, -3, 4};
    cout << subarraysDivByK(nums, 4);
    return 0;
}