#include <iostream>

void cnote()
{
    int X, Y, K, N;
    std::cin >> X >> Y >> K >> N;
    int required_pages = X - Y;
    std::string res = "";
    while (N--)
    {
        int Pi, Ci;
        std::cin >> Pi >> Ci;
        if (required_pages <= Pi && Ci <= K)
            res = "LuckyChef";
    }
    if (res != "")
        std::cout << res << std::endl;
    else
        std::cout << "UnluckyChef\n";
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
        cnote();
    return 0;
}