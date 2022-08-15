#include <iostream>
#include <map>

using namespace std;

void lapin()
{
    string s;
    cin >> s;

    map<char, int> f_half;
    map<char, int> s_half;

    int mid = s.length() / 2;
    for (int i = 0; i < mid; i++)
    {
        if (f_half[s[i]])
            f_half[s[i]] += 1;
        else
            f_half[s[i]] = 1;

        char ch;
        if (s.length() % 2 == 0)
            ch = s[mid + i];
        else
            ch = s[mid + i + 1];

        if (s_half[ch])
            s_half[ch] += 1;
        else
            s_half[ch] = 1;
    }

    string res = "YES";
    if (f_half.size() == s_half.size())
    {
        for (auto x : f_half)
        {
            if (s_half[x.first])
            {
                if (x.second != s_half[x.first])
                {
                    res = "NO";
                    break;
                }
            }
            else
            {
                res = "NO";
                break;
            }
        }
    }
    else
        res = "NO";

    cout << res << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        lapin();
}