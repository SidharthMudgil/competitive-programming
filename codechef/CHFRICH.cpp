#include <iostream>
using namespace std;

long long solve()
{
    long long A, B, X;
    cin >> A >> B >> X;
    return (B - A) / X;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}