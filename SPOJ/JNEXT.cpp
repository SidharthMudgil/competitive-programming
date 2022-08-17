#include <iostream>
#include <cstring>

const int MAX = 1000000;
int a[MAX], cnt[10];

using namespace std;

void jnext()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(cnt, 0, sizeof(int) * 10);
    
    int i , j, k;
    for (i = n - 1; i >= 0; i--)
    {
        cnt[a[i]]++;
        for (j = a[i] + 1; j < 10; j++)
            if (cnt[j])
                break;

        if (j < 10)
        {
            a[i] = j;
            cnt[j]--;

            for (j = 0, k = i + 1; j < 10; j++)
                while (cnt[j]--)
                    a[k++] = j;
            break;
        }
    }

    if (i < 0)
        cout << "-1\n";
    else
    {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        jnext();
    return 0;
}