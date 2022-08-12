#include <iostream>

void merge(int *arr, int begin, int mid, int end)
{
    int l_size = mid - begin + 1;
    int r_size = end - mid;

    int left[l_size];
    int right[r_size];

    for (int i = 0; i < l_size; i++)
        left[i] = arr[begin + i];

    for (int i = 0; i < r_size; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = begin;

    while (i != l_size && j != r_size)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i != l_size)
        arr[k++] = left[i++];

    while (j != r_size)
        arr[k++] = right[j++];
}

void merge_sort(int *arr, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        merge_sort(arr, begin, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, begin, mid, end);
    }
}

int main()
{
    int arr[] = {9, 1, 5, 122, 2, 10, 0, 9};
    int size = sizeof(arr) / sizeof(int);
    merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    return 0;
}