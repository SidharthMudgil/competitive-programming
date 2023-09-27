// USER: SIDHARTH MUDGIL
// DATE: Friday 16, Sep 2022
// TASK: MAX_DIFF

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

#define mod 1000000007

long long solve()
{
    long long N, S;
    cin >> N >> S;

    if (N >= S)
        return S;
    else
        return N - (S - N);
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