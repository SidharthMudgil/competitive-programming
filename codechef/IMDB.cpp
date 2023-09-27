// USER: SIDHARTH MUDGIL
// DATE: Saturday 17, Sep 2022
// TASK: IMDB

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define mod 1000000007

typedef long long ll;

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second > b.second;
}

ll solve()
{
    ll N, X;
    cin >> N >> X;
    vector<pair<ll, ll>> v(N);
    while (N--)
    {
        ll S, R;
        cin >> S >> R;
        pair<ll, ll> p = {S, R};
        v.push_back(p);
    }

    sort(v.begin(), v.end(), comp);

    for (auto m : v)
    {
        if (m.first <= X)
            return m.second;
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cout << solve() << endl;
    }
    return 0;
}