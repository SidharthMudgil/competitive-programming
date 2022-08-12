#include <iostream>

int binary_search(int *arr, int size, int target)
{
    int begin = 0;
    int end = size - 1;
    for (int i = 0; i < size; i++)
    {
        int mid = (begin + end) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target < arr[mid])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 53, 54, 55, 56, 58, 100, 1312, 3425};
    int size = sizeof(arr) / sizeof(int);
    std::cout << binary_search(arr, size, 58);
    return 0;
}