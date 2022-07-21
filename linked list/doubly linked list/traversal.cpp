#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
} * head, *tail;

bool isEmptyList()
{
    return head == NULL;
}

void constructList(int size = 5)
{
    for (int i = size; i >= 1; i--)
    {
        Node *ptr = new Node;
        ptr->data = i;
        ptr->next = head;
        ptr->prev = NULL;
        if (isEmptyList())
        {
            tail = ptr;
        }
        else
        {
            head->prev = ptr;
        }
        head = ptr;
    }
}

void display()
{
    if (isEmptyList())
    {
        cout << "empty list" << endl;
    }
    else
    {
        Node *ptr = head;

        while (ptr != NULL)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    head = tail = NULL;

    constructList();
    display();
    
    return 0;
}