#include <iostream>
#include <map>

unsigned long long grid_traveller(int row, int col, std::map<std::pair<int, int>, unsigned long long> &memo)
{
    if (memo[{row, col}])
        return memo[{row, col}];

    if (row <= 1 || col <= 1)
        return 1;

    memo[{row, col}] = grid_traveller(row - 1, col, memo) + grid_traveller(row, col - 1, memo);
    memo[{col, row}] = memo[{row, col}];

    return memo[{row, col}];
}

int main()
{
    std::map<std::pair<int, int>, unsigned long long> memo = {};
    std::cout << grid_traveller(1, 1, memo);
    return 0;
}