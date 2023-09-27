// USER: SIDHARTH MUDGIL
// DATE: Friday 20, Jan 2023
// TASK: 121. Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int min = INT_MAX;
    int res = 0;
    ;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min)
            min = prices[i];

        res = max(res, prices[i] - min);
    }

    return res;
}

int main()
{
    vector<int> p{1, 22, 52, 6, 34, 3};
    cout << maxProfit(p);
    return 0;
}