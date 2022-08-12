#include <iostream>

void swap(int *arr, int pos, int flag)
{
    int temp;
    temp = arr[pos];
    arr[pos] = arr[flag];
    arr[flag] = temp;
}

int partition(int *arr, int begin, int end)
{
    int left = begin - 1, right = end + 1;
    int pivot = begin;

    while (left < right)
    {
        if (pivot == left)
        {
            do
                right--;
            while (arr[right] > arr[pivot]);

            if (left == right)
                return pivot;

            if (arr[right] < arr[pivot])
            {
                swap(arr, pivot, right);
                pivot = right;
            }
        }
        else
        {
            do
                left++;
            while (arr[left] < arr[pivot]);

            if (left == right)
                return pivot;

            if (arr[left] > arr[pivot])
            {
                swap(arr, pivot, left);
                pivot = left;
            }
        }
    }

    return pivot;
}

void quick_sort(int *arr, int begin, int end)
{
    if (begin < end)
    {
        int pivot = partition(arr, begin, end);
        quick_sort(arr, begin, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int main()
{
    int arr[] = {1, 4, 3, 1, 6, 7, 11, 9, 2, 10, 12};
    int size = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    return 0;
}