#include <iostream>
#include <vector>
#include <algorithm>

void fill_knapsack(std::vector<std::pair<double, double>> items, int capacity)
{
    std::sort(items.begin(), items.end(), [](auto &left, auto &right)
              { return left.first * right.second > right.first * left.second; });

    std::vector<std::pair<std::pair<double, double>, double>> items_picked;
    int total_value = 0;

    for (std::vector<std::pair<double, double>>::iterator it = items.begin(); it != items.end(); ++it)
    {
        if (capacity == 0)
            break;
        else
        {
            if (it->second <= capacity)
            {
                items_picked.push_back(std::make_pair(*it, 1));
                capacity -= it->second;
                total_value += it->first;
            }
            else
            {
                double r = capacity / it->second;
                double v = r * it->first;
                double w = r * it->second;
                std::pair<std::pair<double, double>, double> item = {*it, r};
                items_picked.push_back(item);

                capacity -= w;
                total_value += v;
            }
        }
    }

    for (auto i : items_picked)
        std::cout << i.second * 100 << "\% of item having weight: " << i.first.second << " and value: " << i.first.first << std::endl;

    std::cout << "total value added: " << total_value << std::endl;
}

int main()
{
    std::vector<std::pair<double, double>> items = {{4, 5}, {1, 4}, {3, 5}, {6, 7}, {8, 5}};
    fill_knapsack(items, 20);
    return 0;
}