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

int can_construct(std::string target, std::vector<std::string> words, std::map<std::string, int> &memo)
{
    if (memo.find(target) != memo.end())
        return memo[target];

    if (target.empty())
        return 1;

    int total = 0;
    for (auto word : words)
    {
        std::string remain = remove_substr(target, word);
        if (remain != target)
        {
            int count = can_construct(remain, words, memo);
            total += count;
            memo[target] = total;
        }
    }
    memo[target] = total;
    return total;
}

int main()
{
    std::map<std::string, int> memo = {};
    std::cout << can_construct("aaaa", {"a", "aa", "aaa", "aaaa"}, memo);
    return 0;
}