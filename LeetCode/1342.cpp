// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 1342

#include <iostream>
#include <vector>

using namespace std;

int numberOfSteps(int num)
{
    int result = 0;

    while (num > 0)
    {
        num = (num % 2 == 0) ? num / 2 : num - 1;
        result++;
    }

    return result;
}

int main()
{
    cout << numberOfSteps(3);
    return 0;
}