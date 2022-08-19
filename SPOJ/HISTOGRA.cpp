#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

deque<ll> get_prev(vector<ll> v, int n)
{
    deque<ll> prev;
    stack<ll> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && v.at(i) <= v.at(s.top()))
            s.pop();

        prev.push_back(s.top());
        s.push(i);
    }
    return prev;
}

deque<ll> get_next(vector<ll> v, int n)
{
    deque<ll> next;
    stack<ll> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && v.at(i) <= v.at(s.top()))
            s.pop();

        if (s.top() == -1)
            next.push_front(n);
        else
            next.push_front(s.top());
        s.push(i);
    }
    return next;
}

void histogra(int n)
{
    ll area = 0;
    vector<ll> v;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    deque<ll> prev = get_prev(v, n);
    deque<ll> next = get_next(v, n);

    for (int i = 0; i < n; i++)
        area = max(area, v.at(i) * (next.at(i) - prev.at(i) - 1));

    cout << area << '\n';
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        histogra(n);
    }
}