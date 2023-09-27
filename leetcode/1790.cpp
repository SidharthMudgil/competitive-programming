// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Jan 2023
// TASK: 1790. Check if One String Swap Can Make Strings Equal

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool areAlmostEqual(string s1, string s2)
{
    if (s1 == s2)
        return true;

    vector<pair<char, char>> res;

    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i])
            res.push_back({s1[i], s2[i]});

    return res.size() == 2 && res[0].first == res[1].second && res[0].second == res[1].first;
}

int main()
{
    cout << areAlmostEqual("saf", "fas");
    return 0;
}