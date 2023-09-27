// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Jan 2023
// TASK: 1502. Can Make Arithmetic Progression From Sequence

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeArithmeticProgression(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int d = arr[0] - arr[1];
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (d != arr[i] - arr[i + 1])
            return false;
        d = arr[i] - arr[i + 1];
    }
    return true;
}

int main()
{
    vector<int> v{32, 4, 5, 2, 1};
    cout << canMakeArithmeticProgression(v);
    return 0;
}