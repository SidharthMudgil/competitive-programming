// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 2373. Largest Local Values in a Matrix

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int size = grid.size();
    vector<vector<int>> res(size - 2, vector<int>(size - 2, 0));

    for (int k = 0; k < size - 2; k++)
    {
        for (int m = 0; m < size - 2; m++)
        {
            int max = 0;
            for (int i = k; i < 3 + k; i++)
            {
                for (int j = m; j < 3 + m; j++)
                {
                    if (max < grid[i][j])
                        max = grid[i][j];
                }
            }
            res[k][m] = max;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> grid{{4, 5, 6, 7}, {1, 2, 4, 2}, {1, 9, 9, 2}, {4, 5, 7, 6}};
    vector<vector<int>> res = largestLocal(grid);
    for (auto row : res)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}