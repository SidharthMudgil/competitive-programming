#include <iostream>
#include <vector>

using namespace std;

void cops()
{
    int m, x, y;
    cin >> m >> x >> y;

    vector<int> vec;
    while (m--)
    {
        int n;
        cin >> n;
        vec.push_back(n);
    }
    const int dist = x * y;
    int houses[101] = {0};
    for (int i = 1; i < 101; i++)
        houses[i] = 1;

    for (auto i : vec)
    {
        int l_bound = i - dist < 1 ? 1 : i - dist;
        int h_bound = i + dist > 100 ? 100 : i + dist;

        for (int i = l_bound; i <= h_bound; i++)
            houses[i] = 0;
    }

    int count = 0;
    for (auto x : houses)
        if (x)
            count++;

    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cops();
}