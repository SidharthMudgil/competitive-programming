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

void search()
{
    int node, flag = 0;
    cout << "Enter Node: ";
    cin >> node;

    if (head->data == node)
    {
        cout << "node found @location: " << flag;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL && ptr->data != node)
        {
            ptr = ptr->next;
            flag++;
        }
        if (ptr->data == node)
        {
            cout << "node found @location: " << flag;
        }
        else
        {
            cout << "Node not found";
        }
    }
}

int main()
{
    constructList();
    search();
    return 0;
}