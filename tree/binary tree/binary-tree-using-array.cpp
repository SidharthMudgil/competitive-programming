#include <iostream>

using namespace std;

class BinaryTree
{
    const int size;
    int data[100];

    int getInput(int pos = 1)
    {
        int data;
        cout << "node " << pos << ": ";
        cin >> data;
        return data;
    }

    void inorder(int pos = 1)
    {
        if (pos >= size)
        {
            return;
        }
        inorder(2 * pos);
        cout << data[pos] << " ";
        inorder(2 * pos + 1);
    }
    void preorder(int pos = 1)
    {
        if (pos >= size)
        {
            return;
        }
        cout << data[pos] << " ";
        preorder(2 * pos);
        preorder(2 * pos + 1);
    }
    void postorder(int pos = 1)
    {
        if (pos >= size)
        {
            return;
        }
        postorder(2 * pos);
        postorder(2 * pos + 1);
        cout << data[pos] << " ";
    }

public:
    BinaryTree(int m) : size(m + 1)
    {
        fill(data + 1, data + size + 1, -1);
    }

    void add(int pos = 1)
    {
        data[pos] = getInput(pos);

        if (data[pos] == -1 || pos >= size)
        {
            return;
        }

        add(2 * pos);
        add(2 * pos + 1);
    }

    void display()
    {
        char choice;
        cout << "1 | inorder\n2 | preorder\n3 | postorder\nchoice >>> ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        case 'a':
        case 'A':
            inorder();
            break;

        case '2':
        case 'b':
        case 'B':
            preorder();
            break;

        case '3':
        case 'c':
        case 'C':
            postorder();
            break;

        default:
            break;
        }
    }
};

int main()
{
    BinaryTree bt = BinaryTree(5);
    bt.add();
    bt.display();
    return 0;
}