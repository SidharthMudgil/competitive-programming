#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;
} * head, *tail;

bool isEmptyList()
{
    return head == NULL;
}

void constructList(int size = 10)
{
    for (int i = 0; i < size; i++)
    {
        Node *ptr = new Node;
        ptr->data = i;
        if (isEmptyList())
        {
            ptr->next = ptr;
            ptr->prev = ptr;
            head = ptr;
        }
        else
        {
            tail->next = ptr;
            head->prev = ptr;
            ptr->prev = tail;
            ptr->next = head;
        }
        tail = ptr;
    }
}

void display()
{
    if (isEmptyList())
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

void search(int node)
{
    if (isEmptyList())
    {
        cout << "list empty" << endl;
    }
    else
    {
        Node *ptr = head;
        int pos = 0;

        while (ptr->data != node && ptr->next != head)
        {
            ptr = ptr->next;
            pos++;
        }

        if (ptr->data != node)
        {
            cout << "node not found" << endl;
        }
        else
        {
            cout << "found @ pos " << pos << endl;
        }
    }
}

int main()
{
    head = tail = NULL;
    constructList();
    display();
    search(5);
    search(21);
    search(3);
    return 0;
}