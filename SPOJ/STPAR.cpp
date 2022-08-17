#include <iostream>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

void stpar(int n)
{
    queue<int> q;
    stack<int> s2, s3;
    int a[1000];

    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        q.push(y);
    }

    s3.push(0);
    int x, y, z;
    while (!q.empty())
    {
        x = q.front();
        q.pop();

        if (x == s3.top() + 1)
        {
            s3.push(x);

            while (!s2.empty() && s2.top() == s3.top() + 1)
            {
                s3.push(s2.top());
                s2.pop();
            }
        }
        else
            s2.push(x);
    }

    if (q.empty() && s3.size() == n + 1)
        cout << "yes\n";
    else
        cout << "no\n";
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        stpar(n);
    }
}