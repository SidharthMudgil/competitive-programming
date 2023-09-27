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

    for (int num : numbers)
    {
        std::vector<int> res = how_sum(target_sum - num, numbers, memo);

        if (res.size() == 0 || res.at(0) != -1)
        {
            res.push_back(num);
            memo[target_sum] = res;
            return memo[target_sum];
        }
    }
    memo[target_sum] = {-1};
    return {-1};
}

int main()
{
    std::map<int, std::vector<int>> memo = {};

    std::vector<int> res = how_sum(13, {2, 4, 5}, memo);
    for (int num : res)
        std::cout << num << " ";

    return 0;
}