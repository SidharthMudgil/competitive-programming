// USER: SIDHARTH MUDGIL
// DATE: Saturday 21, Jan 2023
// TASK: 1232.  Check If It Is a Straight Line

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    if (coordinates.size() == 2)
        return true;

    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];

    for (int i = 2; i < coordinates.size(); i++)
    {
        int xi = coordinates[i][0];
        int xi1 = coordinates[i - 1][0];
        int yi = coordinates[i][1];
        int yi1 = coordinates[i - 1][1];

        if ((x0 - x1) * (yi1 - yi) != (y0 - y1) * (xi1 - xi))
            return false;
    }

    return true;
}

int main()
{
    vector<vector<int>> c{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    cout << checkStraightLine(c);
    return 0;
}