#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int MAX = 1e5 + 1;
int cnt[26];


string solve(string s)
{
    deque<char> t, u;

    for (char ch : s)
    {
        if (t.empty())
            t.push_back(ch);
        else if (ch > t.back())
            t.push_back(ch);
        else
        {

        }

        if (u.empty())
        {
            u.push_back(t.back());
            t.pop_back();
        }
    }

    // return u;
}

int main()
{
    string s(MAX, '\0');
    cin >> s;
    cout << solve(s);
    return 0;
}