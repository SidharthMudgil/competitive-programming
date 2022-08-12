#include <iostream>

int find_max(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void counting_sort(int *arr, int size)
{
    const int c_array_size = find_max(arr, size) + 1;
    int count_array[c_array_size];

    for (int i = 0; i < c_array_size; i++)
        count_array[i] = 0;

    for (int i = 0; i < size; i++)
        count_array[arr[i]]++;

    for (int i = 1; i < c_array_size; i++)
        count_array[i] += count_array[i - 1];

    int temp[size];
    for (int i = 0; i < size; i++)
    {
        temp[count_array[arr[i]] - 1] = arr[i];
        count_array[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = temp[i];
}

int main()
{
    int arr[] = {9, 1, 5, 2, 2, 0, 0, 9};
    int size = sizeof(arr) / sizeof(int);
    counting_sort(arr, size);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    return 0;
}