#include <iostream>
#include <vector>

int *sort(int arr[], int size)
{
    int *permutation = new int[size];

    for (int i = 0; i < size; i++)
        permutation[i] = i;

    for (int i = size; i >= 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                temp = permutation[j];
                permutation[j] = permutation[j + 1];
                permutation[j + 1] = temp;
            }
        }
    }

    return permutation;
}

void greedy_iterative_activity_selector(char activity[], int start[], int finish[], int size)
{
    int *permutation = sort(finish, size);
    std::vector<int> set;
    set.push_back(permutation[0]);

    int end = finish[0];
    for (int i = 1; i < size; i++)
    {
        int pos = permutation[i];
        if (start[pos] >= end)
        {
            set.push_back(pos);
            end = finish[i];
        }
    }

    for (int i = 0; i < set.size(); i++)
    {
        char a = activity[set[i]];
        int s = start[set[i]];

        std::cout << "Activity " << a << ":\n\tstarted at: " << s << "\n\tfinished at: " << finish[i] << std::endl;
    }
}

int main()
{
    char actvity[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    greedy_iterative_activity_selector(actvity, start, finish, 6);
    return 0;
}