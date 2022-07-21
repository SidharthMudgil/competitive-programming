#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
} * head;

class BTree
{
    int get_input()
    {
        int data;
        cout << "enter data(alpha to cancel): ";
        try
        {
            cin >> data;
            if (cin.fail())
                throw runtime_error("you cancelled further child nodes");
            else
                return data;
        }
        catch (const runtime_error err)
        {
            cerr << err.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
    }

    void inorder(Node *node = head)
    {
        if (node == NULL)
        {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void preorder(Node *node = head)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node *node = head)
    {
        if (node == NULL)
        {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BTree()
    {
        head = NULL;
    }

    Node *add()
    {
        Node *ptr = new Node;
        ptr->data = get_input();

        if (head == NULL)
        {
            head = ptr;
        }

        if (ptr->data == -1)
        {
            return NULL;
        }

        ptr->left = add();
        ptr->right = add();
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
    BTree bt = BTree();
    bt.add();
    bt.display();
    return 0;
}