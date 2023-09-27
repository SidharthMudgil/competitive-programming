#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void jnext()
{
    int n;
    cin >> n;
    stack<int> no;
    
    while (n--)
    {
        int x;
        cin >> x;
        no.push(x);
    }

    vector<int> vec;
    vec.push_back(no.top());
    no.pop();

    while (!no.empty())
    {
        int x = no.top();
        vec.push_back(x);
        no.pop();

        int y = -1;
        for (auto z : vec)
        {
            if (x < z)
            {
                y = z;
                break;
            }
        }
        if (y != -1)
        {
            no.push(y);
            auto it = find(vec.begin(), vec.end(), y);
            if (it != vec.end())
                vec.erase(it);
            sort(vec.begin(), vec.end());

            for (auto z : vec)
                no.push(z);

            int num = 0;
            int tens = 1;
            while (!no.empty())
            {
                num += tens * no.top();
                tens *= 10;
                no.pop();
            }
            cout << num << "\n";
            return;
        }
    }

    cout << "-1\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        jnext();
    return 0;
}