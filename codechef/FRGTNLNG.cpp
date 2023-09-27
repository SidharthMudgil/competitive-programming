#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void frgtnlng()
{
    int n, k;
    cin >> n >> k;
    vector<string> words, vec;
    while (n--)
    {
        string s;
        cin >> s;
        words.push_back(s);
    }
    while (k--)
    {
        int l;
        cin >> l;
        while (l--)
        {
            string s;
            cin >> s;
            vec.push_back(s);
        }
    }

    for (auto word : words)
    {
        if (find(vec.begin(), vec.end(), word) != vec.end())
            cout << "YES ";
        else
            cout << "NO ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        frgtnlng();
    return 0;
}