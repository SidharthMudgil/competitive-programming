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

    std::vector<int> res;
    for (int num : numbers)
    {
        memo[target_sum] = how_sum(target_sum - num, numbers, memo);

        if (memo[target_sum].size() == 0 || memo[target_sum].at(0) != -1)
        {
            res = memo[target_sum];
            res.push_back(num);
            return res;
        }
    }

    return {-1};
}

int main()
{
    std::map<int, std::vector<int>> memo = {};
    std::vector<int> comb = {};

    std::vector<int> res = how_sum(300, {7, 14}, memo);
    for (int num : res)
        std::cout << num << " ";

    return 0;
}