#include <iostream>
#include <stack>
using namespace std;

const int MAX = 1e5 + 1;

int calc(int *arr, int n)
{
    int res = 0;

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty())
        {
            res = max(res, arr[i] ^ st.top());
            if (arr[i] < st.top())
                break;
            else
                st.pop();
        }
        st.push(arr[i]);
    }

    return res;
}

int main()
{
    int n, arr[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << calc(arr, n);
}