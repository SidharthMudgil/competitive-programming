// USER: SIDHARTH MUDGIL
// DATE: Saturday 17, Sep 2022
// TASK: PROGLANG

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
    int A, B, A1, B1, A2, B2;
    cin >> A >> B >> A1 >> B1 >> A2 >> B2;

    if ((A == A1 || A == B1) && (B == A1 || B == B1))
        return 1;
    if ((A == A2 || A == B2) && (B == A2 || B == B2))
        return 2;
    else
        return 0;
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