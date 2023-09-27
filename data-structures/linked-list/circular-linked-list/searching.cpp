#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    Node *next;
    int data;
} * head;

bool isListEmpty()
{
    return head == NULL;
}

void constructList(int size = 10)
{
    for (int i = size; i >= 1; i--)
    {
        Node *ptr = new Node;
        ptr->data = i;
        if (isListEmpty())
        {
            ptr->next = ptr;
        }
        else
        {
            Node *temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            ptr->next = head;
            temp->next = ptr;
        }

        head = ptr;
    }
}

void display()
{
    if (isListEmpty())
    {
        cout << "list empty" << endl;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != head)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
}

void search()
{
    if (isListEmpty())
    {
        cout << "list empty" << endl;
    }
    else
    {
        int node, pos = 0;
        cout << "what? ";
        cin >> node;

        Node *ptr = head;
        while (ptr->data != node && ptr->next != head)
        {
            ptr = ptr->next;
            pos += 1;
        }

        if (ptr->data == node)
        {
            cout << "node found & pos " << pos << endl;
        }
        else
        {
            cout << "node not found" << endl;
        }
    }
}

int main()
{
    head = NULL;
    constructList();
    display();
    search();
    search();
    search();
    search();
    return 0;
}