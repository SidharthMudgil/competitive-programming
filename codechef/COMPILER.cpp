#include <iostream>

using namespace std;

void compiler()
{
    string s;
    cin >> s;
    int count = 0;
    int top = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
            top++;
        else
            top--;

        if (top < 0)
            break;

        if (top == 0)
            count = i + 1;
    }

    std::cout << count << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        compiler();
}