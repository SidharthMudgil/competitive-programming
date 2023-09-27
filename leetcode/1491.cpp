// USER: SIDHARTH MUDGIL
// DATE: Tuesday 17, Jan 2023
// TASK: 1491. Average Salary Excluding the Minimum and Maximum Salary

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

double average(vector<int> &salary)
{
    sort(salary.begin(), salary.end());
    double x = accumulate(salary.begin() + 1, salary.end() - 1, 0);
    return x / (salary.size() - 2);
}

int main()
{
    vector<int> salary{1, 2, 3, 4};
    cout << average(salary);
    return 0;
}