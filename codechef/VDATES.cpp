// USER: SIDHARTH MUDGIL
// DATE: Saturday 17, Sep 2022
// TASK: VDATES

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

string solve()
{
    ll D, L, R;
    cin >> D >> L >> R;

    if (D > R)
        return "Too Late";
    else if(D < L)
        return "Too Early";
    else
        return "Take second dose now";
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