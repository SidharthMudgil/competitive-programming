#include <iostream>

void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i, temp = arr[i];
        while (j > 0 && temp < arr[j - 1])
            arr[j--] = arr[j - 1];
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {9, 1, 5, 2, 2, 0, -10, 9};
    int size = sizeof(arr) / sizeof(int);
    insertion_sort(arr, size);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    return 0;
}