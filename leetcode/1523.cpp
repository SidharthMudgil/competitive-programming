// USER: SIDHARTH MUDGIL
// DATE: Tuesday 17, Jan 2023
// TASK: 1523. Count Odd Numbers in an Interval Range

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countOdds(int low, int high)
{
    int count = (high - low) / 2;
    return low % 2 != 0 || high % 2 != 0 ? ++count : count;
}

int main()
{
    cout << countOdds(1, 3);
    return 0;
}