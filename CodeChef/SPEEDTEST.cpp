#include <iostream>
using namespace std;

string solve()
{
    long long A, X, B, Y;
    cin >> A >> X >> B >> Y;

    long long alice = A * Y;
    long long bob = B * X;

    if (alice > bob)
        return "Alice";
    else if (alice < bob)
        return "Bob";
    else
        return "Equal";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}
