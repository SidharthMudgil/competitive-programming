// USER: SIDHARTH MUDGIL
// DATE: Tuesday 17, Jan 2023
// TASK: 205. Isomorphic Strings

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t)
{
    map<char, int> a;
    map<char, int> b;

    for (int i = 0; i < s.size(); i++)
    {
        char ch1 = s[i];
        char ch2 = t[i];

        if (a[ch1] == 0 && b[ch2] == 0)
        {
            a[ch1] = ch2;
            b[ch2] = ch1;
        }

        else if (a[ch1] != ch2 && b[ch2] != ch1)
            return false;
    }

    return true;
}

int main()
{
    cout << isIsomorphic("aabs", "aacs");
    return 0;
}