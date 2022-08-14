#include <iostream>

int chn15a()
{
    int N, K;
    std::cin >> N >> K;
    int res = 0;
    while (N--)
    {
        int x;
        std::cin >> x;
        if ((x + K) % 7 == 0)
            res += 1;
    }
    return res;
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
        std::cout << chn15a() << '\n';
    return 0;
}