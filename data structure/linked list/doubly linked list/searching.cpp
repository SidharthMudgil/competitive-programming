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

int getInput(string msg)
{
    int data;
    cout << msg;
    cin >> data;
    return data;
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

void searchStart()
{
    int pos = 0;
    int node = getInput("which? ");

    Node *ptr = head;
    while (ptr->data != node && ptr->next != NULL)
    {
        ptr = ptr->next;
        pos++;
    }
    if (ptr->data == node)
    {
        cout << "node found @ pos " << pos << " from start" << endl;
    }
    else
    {
        cout << "node not found" << endl;
    }
}

void searchEnd()
{
    int pos = 0;
    int node = getInput("which? ");

    Node *ptr = tail;
    while (ptr->data != node && ptr->prev != NULL)
    {
        ptr = ptr->prev;
        pos++;
    }
    if (ptr->data == node)
    {
        cout << "node found @ pos " << pos << " from end" << endl;
    }
    else
    {
        cout << "node not found" << endl;
    }
}

int main()
{
    head = tail = NULL;

    constructList();
    display();
    searchStart();
    searchEnd();
    searchStart();
    searchEnd();
    searchStart();
    searchEnd();
    
    return 0;
}