// USER: SIDHARTH MUDGIL
// DATE: Saturday 17, Sep 2022
// TASK: HOOPS

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define mod 1000000007

typedef long long ll;

ll solve()
{
    ll N;
    cin >> N;
    return N / 2 + 1;
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