#include <iostream>
using namespace std;

void csub()
{
    long n;
    string s;
    cin >> n >> s;

    long count = 0;
    for (long i = 0; i < n; i++)
        if (s[i] == '1')
            count++;
    cout << (count * (count + 1)) / 2 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        csub();
}