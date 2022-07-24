#include <iostream>
#include <vector>
#include <algorithm>

void fill_knapsack(std::vector<std::pair<int, int>> items, int capacity)
{
    std::sort(items.begin(), items.end(), [](auto &left, auto &right)
              { return left.first * right.second > right.first * left.second; });

    std::vector<std::pair<int, int>> items_picked;
    int total_value = 0;

    for (std::vector<std::pair<int, int>>::iterator it = items.begin(); it != items.end(); ++it)
    {
        if (capacity > 0 && it->second <= capacity)
        {
            items_picked.push_back(*it);
            capacity -= it->second;
            total_value += it->first;
        }
    }

    for (auto i : items_picked)
        std::cout << "Item picked with value: " << i.first << " weight: " << i.second << std::endl;

    std::cout << "capacity remaining: " << capacity << std::endl;
    std::cout << "total value added: " << total_value << std::endl;
}

int main()
{
    std::vector<std::pair<int, int>> items = {{4, 5}, {1, 4}, {3, 5}, {6, 7}, {8, 8}};
    fill_knapsack(items, 20);
    return 0;
}