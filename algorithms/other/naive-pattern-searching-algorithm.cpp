#include <iostream>
#include <string>
#include <vector>

typedef std::vector<int> vector;

vector search(std::string pattern, std::string text)
{
    if (pattern.length() > text.length())
        return {};

    vector res;
    int window_size = pattern.length() - 1;
    auto it = text.begin();
    while (it != (text.end() - window_size))
    {
        auto it1 = it;
        auto it2 = pattern.begin();
        while (it2 != pattern.end())
        {
            if (*it1 != *it2)
                break;
            ++it1;
            ++it2;
        }
        if (it2 == pattern.end())
            res.push_back(std::distance(text.begin(), it));
        ++it;
    }

    return res;
}

int main()
{
    vector res = search("flow", "i love stackoverflow");

    if (!res.empty())
        for (auto pos : res)
            std::cout << "Pattern found at index " << pos << std::endl;
    else
        std::cout << "Pattern not exist\n";

    return 0;
}