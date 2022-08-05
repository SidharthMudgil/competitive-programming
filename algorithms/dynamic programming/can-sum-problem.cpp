#include <iostream>
#include <vector>
#include <map>

int can_sum(long target_sum, std::vector<int> numbers, std::map<int, bool> &memo)
{
    if (memo.find(target_sum) != memo.end())
        return memo[target_sum];

    if (target_sum == 0)
        return true;

    if (target_sum < 0)
        return false;

    for (int num : numbers)
    {
        memo[target_sum] = can_sum(target_sum - num, numbers, memo);
        if (memo[target_sum])
            return true;
    }

    return false;
}

int main()
{
    std::map<int, bool> memo = {};

    if (can_sum(13, {2, 4, 5}, memo))
        std::cout << "True";
    else
        std::cout << "False";
    return 0;
}