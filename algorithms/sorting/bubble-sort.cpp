#include <iostream>

void swap(int *arr, int pos)
{
    int temp;
    temp = arr[pos];
    arr[pos] = arr[pos + 1];
    arr[pos + 1] = temp;
}

void bubble_sort(int *arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j);
}

int main()
{
    int arr[] = {9, 1, 5, 2, 2, 0, 0, 9};
    int size = sizeof(arr) / sizeof(int);
    bubble_sort(arr, size);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    return 0;
}