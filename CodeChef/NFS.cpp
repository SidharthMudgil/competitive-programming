// USER: SIDHARTH MUDGIL
// DATE: Saturday 17, Sep 2022
// TASK: NFS

#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string.h>
#include <algorithm>
#include <limits>
#include <math.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

string solve()
{
    ll U, V, A, S;
    cin >> U >> V >> A >> S;

    if (U <= V)
        return "YES";

    ll v2 = pow(U, 2) - 2 * A * S;

    if (v2 <= pow(V, 2))
        return "YES";
    return "NO";
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