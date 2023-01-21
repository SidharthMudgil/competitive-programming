// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Jan 2023
// TASK: 409. Longest Palindrome

#include <iostream>
#include <map>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
    int res = 0;
    map<char, int> m;

    for (auto ch : s)
        m[ch]++;

    for (auto it : m)
    {
        if ((it.second % 2 != 0 && !res) || !res || res % 2 == 0)
            res += it.second;
        else
        {
            if (it.second % 2 == 0)
                res += it.second;
            else
                res += it.second - 1;
        }
    }

    return res;
}

int main()
{
    cout << longestPalindrome("asfauigwdssss");
    return 0;
}