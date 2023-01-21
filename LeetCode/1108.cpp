// USER: SIDHARTH MUDGIL
// DATE: Thursday 19, Jan 2023
// TASK: 1108. Defanging an IP Address

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string defangIPaddr(string address)
{
    string res = "";
    for (auto ch : address)
    {
        if (ch == '.')
            res += "[.]";
        else
            res += ch;
    }

    return res;
}

int main()
{
    cout << defangIPaddr("3.4.3.4");
    return 0;
}