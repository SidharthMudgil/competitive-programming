// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Jan 2023
// TASK: 496. Next Greater Element I

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    map<int, int> m;

    for (int i = 0; i < nums2.size(); i++)
        m[nums2[i]] = i;

    vector<int> res;

    for (int i = 0; i < nums1.size(); i++)
    {
        int j = m[nums1[i]] + 1;

        for (j; j < nums2.size(); j++)
        {
            if (nums2[j] > nums1[i])
            {
                res.push_back(nums2[j]);
                break;
            }
        }

        if (j == nums2.size())
            res.push_back(-1);
    }

    return res;
}

int main()
{
    vector<int> a{1, 2, 4, 6};
    vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> r = nextGreaterElement(a, b);
    return 0;
}