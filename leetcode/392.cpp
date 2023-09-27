// USER: SIDHARTH MUDGIL
// DATE: Tuesday 17, Jan 2023
// TASK: 392. Is Subsquence

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSubsequence(string s, string t)
{
    if (s.size() > t.size())
        return false;
    else if (s == t)
        return true;

    int i = 0;

    for (int j = 0; j < t.size(); j++)
    {
        if (s[i] == t[j])
            i++;

        if (i == s.size())
            return true;
    }

    return false;
}

int main()
{
    cout << isSubsequence("sf", "saf");
    return 0;
}