#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * head;

bool isListEmpty()
{
    return head == NULL;
}

void constructList(int size = 5)
{
    for (int i = 0; i < size; i++)
    {
        Node *ptr = new Node;
        isListEmpty() ? ptr->next = NULL : ptr->next = head;
        ptr->data = i;
        head = ptr;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "List Empty";
    }
    else
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << "->";
            ptr = ptr->next;
        }
        cout << "NULL";
    }
}

int main()
{
    constructList(20);
    display();
    return 0;
}