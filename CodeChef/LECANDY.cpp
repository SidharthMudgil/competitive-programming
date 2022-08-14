#include <iostream>

void lecandy(int T)
{
    std::string res[T];

    for (int i = 0; i < T; i++)
    {
        int N, C;
        std::cin >> N >> C;
        int sum = 0;
        while (N > 0)
        {
            int x;
            std::cin >> x;
            sum += x;
            N--;
        }
        res[i] = sum <= C ? "Yes" : "No";
    }

    for (auto i : res)
        std::cout << i << "\n";
}

int main()
{
    int T;
    std::cin >> T;
    lecandy(T);
    return 0;
}