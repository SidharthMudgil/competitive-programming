// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 1672. Richest Customer Wealth

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int result = 0;

    for (vector<int> customer : accounts)
    {
        result = max(result, reduce(customer.begin(), customer.end()));
    }

    return result;
}

int main()
{
    vector<vector<int>> accounts{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << maximumWealth(accounts);
    return 0;
}