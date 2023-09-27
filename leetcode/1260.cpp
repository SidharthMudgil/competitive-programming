// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 1260. Shift 2D Grid

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> res(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[(i + (j + k) / n) % m][(j + k) % n] = grid[i][j];
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> x{{1, 2}, {3, 4}, {2, 3}};
    vector<vector<int>> y = shiftGrid(x, 3);
    return 0;
}