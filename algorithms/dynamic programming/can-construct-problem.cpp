#include <iostream>
#include <string>
#include <vector>
#include <map>

std::string remove_substr(std::string str, std::string substr)
{
    int start_pos = str.find(substr);
    int end_pos = substr.length();
    if (start_pos == 0)
        str.erase(start_pos, end_pos);
    return str;
}

bool can_construct(std::string target, std::vector<std::string> words, std::map<std::string, bool> &memo)
{
    if (memo.find(target) != memo.end())
        return memo[target];

    if (target.empty())
        return true;

    for (auto word : words)
    {
        std::string remain = remove_substr(target, word);

        if (remain != target)
        {
            if (can_construct(remain, words, memo))
            {
                memo[target] = true;
                return true;
            }
        }
    }
    memo[target] = false;
    return false;
}

int main()
{
    std::map<std::string, bool> memo = {};

    if (can_construct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"ee", "eee", "eeee", "eeeee", "eeeeee"}, memo))
        std::cout << "true\n";
    else
        std::cout << "false\n";

    return 0;
}