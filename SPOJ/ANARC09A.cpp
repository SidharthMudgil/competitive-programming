#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int anarc09a(string str)
{
    stack<char> st;
    if (str.length() == 0)
        return 0;

    int count = 0;

    for (auto ch : str)
    {
        if (ch == '{')
            st.push(ch);
        else
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }

    while (!st.empty())
    {
        char ch = st.top();
        st.pop();

        if (ch == '{')
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            count++;
        }
        else
        {
            if (!st.empty() && st.top() == '}')
                st.pop();
            count++;
        }
    }
    return count;
}

int main()
{
    int k = 1;
    while (true)
    {
        string str;
        cin >> str;
        if (str.at(0) == '-')
            break;
        cout << k++ << ". " << anarc09a(str) << '\n';
    }
    return 0;
}