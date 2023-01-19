// USER: SIDHARTH MUDGIL
// DATE: Thursday 19, Jan 2023
// TASK: 557. Reverse Words in a String III

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string reverseWords(string s)
{
    int l = 0;
    int r = 0;
    for (auto ch : s)
    {
        if (ch == ' ')
        {
            reverse(s.begin() + l, s.begin() + r);
            l = r + 1;
        }
        r++;
    }

    if (r <= s.size())
        reverse(s.begin() + l, s.begin() + r);

    return s;
}

int main()
{
    cout << reverseWords("My name is Sidharth");
    return 0;
}