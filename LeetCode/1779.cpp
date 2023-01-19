// USER: SIDHARTH MUDGIL
// DATE: Thursday 19, Jan 2023
// TASK: 1779. Find Nearest Point That Has the Same X or Y Coordinate

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int nearestValidPoint(int x, int y, vector<vector<int>> &points)
{
    int min = INT_MAX;
    int res = -1;
    for (int i = 0; i < points.size(); i++)
    {
        if (x == points[i][0] || y == points[i][1])
        {
            int dis = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (dis < min)
            {
                min = dis;
                res = i;
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> points{{1, 4}, {2, 5}, {1, 4}};
    cout << nearestValidPoint(1, 2, points);
    return 0;
}