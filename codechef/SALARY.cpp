#include <iostream>
#include <vector>

int salary()
{
    int N;
    std::cin >> N;

    std::vector<int> w;
    int min = 10000;
    while (N--)
    {
        int x;
        std::cin >> x;
        w.push_back(x);
        if (min > x)
            min = x;
    }
    int res = 0;
    for (auto i : w)
        res += i - min;

    return res;
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
        std::cout << salary() << "\n";
    return 0;
}