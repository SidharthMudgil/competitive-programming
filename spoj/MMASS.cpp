#include <iostream>
#include <map>
#include <stack>

using namespace std;
const map<char, int> M = {{'H', 1}, {'C', 12}, {'O', 16}};

void mmass()
{
    string in;
    cin >> in;

    stack<int> s;
    for (auto ch : in)
    {
        if (ch == '(')
            s.push(ch);
        else if (ch == 'H' || ch == 'C' || ch == 'O')
            s.push(M.at(ch));
        else if (ch >= '2' && ch <= '9')
        {
            int n = ch - '0';
            int m = n * s.top();
            s.pop();
            s.push(m);
        }
        else
        {
            int m = 0;
            while (!s.empty() && s.top() != '(')
            {
                m += s.top();
                s.pop();
            }
            s.pop();
            s.push(m);
        }
    }

    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}

int main()
{
    mmass();
    return 0;
}