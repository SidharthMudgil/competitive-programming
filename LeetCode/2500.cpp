// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 2500. Delete Greatest Value in Each Row

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int deleteGreatestValue(vector<vector<int>> &grid)
{
    int m = grid.size();
    int sum = 0;

    while (m)
    {
        int max = 0;
        sort(grid[m - 1].begin(), grid[m - 1].end());
        m--;
    }

    for (int i = 0; i < grid[0].size(); i++)
    {
        int max = 0;
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[j][i] > max)
                max = grid[j][i];
        }
        sum += max;
    }

    return sum;
}

int main()
{
    vector<vector<int>> grid{{1, 2, 3}, {2, 3, 4}};
    cout << deleteGreatestValue(grid);
    return 0;
}