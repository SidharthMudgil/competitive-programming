#include <iostream>
using namespace std;

int main()
{
    //defining column size is must, here's 2
    //total elements = 6;
    //total columns  = 2;
    //total row = elements/columns = 3
    int arr[][2] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}