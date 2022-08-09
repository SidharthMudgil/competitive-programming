#include <iostream>
#include <string>
#include <vector>
#include <map>

#define NONE "#1964hf821nur214"

typedef std::map<std::string, std::vector<std::vector<std::string>>> MEMO;
typedef std::vector<std::vector<std::string>> ARR_ARR;

std::string remove_substr(std::string str, std::string substr)
{
    int start_pos = str.find(substr);
    int end_pos = substr.length();
    if (start_pos == 0)
        str.erase(start_pos, end_pos);
    return str;
}

ARR_ARR all_construct(std::string target, std::vector<std::string> words, MEMO &memo)
{
    if (memo.find(target) != memo.end())
        return memo[target];

    if (target.empty())
        return {{}};

    ARR_ARR all_comb;
    for (auto word : words)
    {
        std::string remain = remove_substr(target, word);
        if (remain != target)
        {
            ARR_ARR res = all_construct(remain, words, memo);
            if (!res.empty())
            {
                for (auto comb : res)
                {
                    comb.push_back(word);
                    all_comb.push_back(comb);
                }
                memo[target] = all_comb;
            }
        }
    }
    memo[target] = all_comb;
    return all_comb;
}

int main()
{
    MEMO memo = {};
    ARR_ARR res = all_construct("aabaa", {"a", "aa", "b", "aaa", "aaaa"}, memo);

    bool combination_available = res.size() > 1;

    if (combination_available)
    {
        for (auto comb : res)
        {
            for (auto str : comb)
                std::cout << str << " ";
            std::cout << std::endl;
        }
    }
    else
        std::cout << "combination not avaiable";

    return 0;
}