#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

const map<char, int> P = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};

void onp()
{
    string exp;
    cin >> exp;

    string res;
    stack<char> s;
    for (auto ch : exp)
    {
        if (ch == '(')
            s.push(ch);
        else if (ch >= 'a' && ch <= 'z')
            res += ch;
        else
        {
            if (ch == ')')
            {
                while (s.top() != '(')
                {
                    res += s.top();
                    s.pop();
                }
                s.pop();
            }
            else
            {
                if (s.top() == '(' || P.at(ch) > P.at(s.top()))
                    s.push(ch);
                else
                {
                    res += s.top();
                    s.pop();
                    s.push(ch);
                }
            }
        }
    }

    cout << res << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        onp();
    return 0;
}