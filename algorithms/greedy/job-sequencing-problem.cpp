#include <iostream>
#include <vector>
#include <algorithm>

void sequence(std::vector<std::pair<int, int>> jobs, int n)
{
    std::sort(jobs.begin(), jobs.end(), [](auto &left, auto &right)
              { return left.first > right.first; });

    std::vector<std::pair<int, std::pair<int, int>>> job_sequence;
    std::vector<int> occupied;
    int profit = 0;
    for (auto it = jobs.begin(); it != jobs.end(); it++)
    {
        int slot = it->second - 1;
        while (slot >= 0)
        {
            if (std::find(occupied.begin(), occupied.end(), slot) != occupied.end())
                slot--;
            else
            {
                job_sequence.push_back({slot, *it});
                occupied.push_back(slot);
                profit += it->first;
                break;
            }
        }
    }
    std::sort(job_sequence.begin(), job_sequence.end(), [](auto &left, auto &right)
              { return left.first < right.first; });

    for (auto job : job_sequence)
    {
        std::cout << "Job started at time: " << job.first << "\n";
        std::cout << "Profit: " << job.second.first << "\tDeadline: " << job.second.second << "\n\n";
    }
    std::cout << "Total Profit: " << profit;
}

int main()
{
    int n = 5;
    std::vector<std::pair<int, int>> jobs = {{35, 3}, {30, 4}, {25, 4}, {20, 2}, {15, 3}, {12, 1}, {5, 2}};
    sequence(jobs, n);
    return 0;
}