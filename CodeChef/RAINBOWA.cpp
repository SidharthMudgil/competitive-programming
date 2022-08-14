#include <iostream>

std::string rainbowa()
{
    int N;
    std::cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        std::cin >> A[i];

    if (A[0] != 1 || A[N - 1] != 1)
        return "no";

    int curr = 1;
    for (int i = 1; i <= N / 2; i++)
    {
        if (A[i] != A[N - i - 1])
            return "no";

        if (A[i] != curr)
        {
            if (A[i - 1] == curr)
            {
                if (A[i] == curr + 1)
                    curr++;
                else
                    return "no";
            }
            else
                return "no";
        }
    }
    return curr == 7 ? "yes" : "no";
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
        std::cout << rainbowa() << '\n';
}