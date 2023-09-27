// USER: SIDHARTH MUDGIL
// DATE: Saturday 17, Sep 2022
// TASK: TWODISH

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define mod 1000000007

typedef long long ll;

string solve()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    if (B < N)
        return "NO";
    else if(A + C < N) 
        return "NO";
    else
        return "YES";
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