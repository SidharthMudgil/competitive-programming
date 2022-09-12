#include <iostream>

using namespace std;

long long int solve()
{
    long long int N, M, X;
    cin >> N >> M >> X;

    return (2 * (N + M)) * X;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}