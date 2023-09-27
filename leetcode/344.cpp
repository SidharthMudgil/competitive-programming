// USER: SIDHARTH MUDGIL
// DATE: Thursday 19, Jan 2023
// TASK: 344. Reverse String

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseString(vector<char> &s)
{
    int r = s.size() - 1;

    for (int l = 0; l < s.size() / 2; l++)
    {
        s[l] = s[l] + s[r];
        s[r] = s[l] - s[r];
        s[l] = s[l] - s[r--];
    }
}

int main()
{
    vector<char> s{'f', 'a', 'f', 's', '2'};
    reverseString(s);
    return 0;
}