#include <iostream>
#include <vector>
#include <map>

std::vector<int> how_sum(long target_sum, std::vector<int> numbers, std::map<int, std::vector<int>> &memo)
{
    if (memo.find(target_sum) != memo.end())
        return memo[target_sum];

    if (target_sum == 0)
        return {};

    if (target_sum < 0)
        return {-1};

    std::vector<int> res = {-1};
    for (int num : numbers)
    {
        std::vector<int> comb = how_sum(target_sum - num, numbers, memo);

        if (comb.size() == 0 || comb.at(0) != -1)
        {
            comb.push_back(num);
            if (res.size() == 0 || res.at(0) == -1 || comb.size() < res.size())
                res = comb;
        }
    }
    memo[target_sum] = res;
    return res;
}

int main()
{
    std::map<int, std::vector<int>> memo = {};

    std::vector<int> res = how_sum(300, {2, 4, 5}, memo);
    for (int num : res)
        std::cout << num << " ";

    return 0;
}