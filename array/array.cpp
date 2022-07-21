#include <iostream>

using namespace std;

class Array
{
private:
    int size;
    int arr[];

public:
    Array() { size = 0; }

    void insert(int val, int pos)
    {
        int j = pos;

        size += 1;
        while (j < size)
        {
            int temp = arr[j];
            arr[j] = val;
            val = temp;
            j++;
        }
    }

    void remove(int pos)
    {
        int j = pos;
        size--;

        while (j < size)
        {
            arr[j] = arr[j + 1];
            j++;
        }
        arr[j] = -1;
    }

    void update(int val, int pos)
    {
        cout << arr[pos] << " changed to " << val << endl;;
        arr[pos] = val;
    }

    void search(int target)
    {
        int pos = 0;
        for (pos = 0; pos < size; pos++)
            if (arr[pos] == target)
                break;

        if (pos != size)
            cout << "found at pos: " << pos << endl;
        else
            cout << "not found" << endl;
    }

    void traverse()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Array arr = Array();
    arr.insert(4, 0);
    arr.insert(3, 1);
    arr.insert(2, 2);
    arr.insert(5, 3);
    arr.insert(6, 4);
    arr.insert(1, 5);
    arr.insert(7, 6);
    arr.traverse();

    arr.insert(100, 3);
    arr.remove(5);
    arr.update(1000, 0);
    arr.traverse();

    arr.search(34);
    return 0;
}