// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Jan 2023
// TASK: 491. Non-decreasing Subsequences

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    set<vector<int>> res;

    for (int bitmask = 1; bitmask < (1 << nums.size()); bitmask++)
    {
        vector<int> seq;

        for (int i = 0; i < nums.size(); i++)
        {
            if (((bitmask >> i) & 1) == 1)
                seq.push_back(nums[i]);
        }

        if (seq.size() > 1)
        {
            int k = 0;
            bool isNonDecreasing = true;
            while (isNonDecreasing && k < seq.size() - 1)
            {
                isNonDecreasing &= seq[k] <= seq[k + 1];
                k++;
            }

            if (isNonDecreasing)
                res.insert(seq);
        }
    }

    return {res.begin(), res.end()};
}

int main()
{
    vector<int> v{1, 2, 35, 6, 78, 8};
    vector<vector<int>> res = findSubsequences(v);
    return 0;
}