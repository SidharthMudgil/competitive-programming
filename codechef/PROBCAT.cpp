// USER: SIDHARTH MUDGIL
// DATE: Saturday 17, Sep 2022
// TASK: PROBCAT

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
    int x;
    cin >> x;
    if (1 <= x && x < 100)
        return "EASY";
    if (100 <= x && x < 200)
        return "MEDIUM";
    if (200 <= x && x < 300)
        return "HARD";
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