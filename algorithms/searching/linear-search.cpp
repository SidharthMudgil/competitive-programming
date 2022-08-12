#include <iostream>

int linear_search(int *arr, int size, int target)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int main()
{
    int arr[] = {3, 12, 1, 5, 6, 4, 2};
    int size = sizeof(arr) / sizeof(int);
    std::cout << linear_search(arr, size, 2);
    return 0;
}