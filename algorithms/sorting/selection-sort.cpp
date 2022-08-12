#include <iostream>

void swap(int *arr, int pos, int flag)
{
    int temp;
    temp = arr[pos];
    arr[pos] = arr[flag];
    arr[flag] = temp;
}

void selection_sort(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
            if (arr[min] > arr[j])
                min = j;

        if (i != min)
            swap(arr, i, min);
    }
}

int main()
{
    int arr[] = {9, 21, 5, 2, 2, 0, 0, 9};
    int size = sizeof(arr) / sizeof(int);
    selection_sort(arr, size);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    return 0;
}