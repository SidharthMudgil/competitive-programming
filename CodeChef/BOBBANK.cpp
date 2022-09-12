#include <iostream>
using namespace std;

int solve()
{
    int W, X, Y, Z;
    cin >> W >> X >> Y >> Z;
    return W + Z * X - Z * Y;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}
