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

bool isSingleElement()
{
    return head == tail;
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

void deleteStart()
{
    if (isEmptyList())
    {
        cout << "empty list" << endl;
    }
    else if (isSingleElement())
    {
        cout << head->data << " deleted from start" << endl;
        head = tail = NULL;
    }
    else
    {
        cout << head->data << " deleted from start" << endl;
        Node *ptr = head;
        head = ptr->next;
        ptr->next = NULL;
        head->prev = NULL;
        free(ptr);
    }
}

void deleteEnd()
{
    if (isEmptyList())
    {
        cout << "empty list" << endl;
    }
    else if (isSingleElement())
    {
        cout << head->data << " deleted from end" << endl;
        head = tail = NULL;
    }
    else
    {
        cout << tail->data << " deleted from end" << endl;
        Node *ptr = tail;
        tail = ptr->prev;
        ptr->prev = NULL;
        tail->next = NULL;
        free(ptr);
    }
}

void deleteNode()
{
    int node = getInput("which? ");

    Node *ptr = head;
    while (ptr->data != node && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL && ptr->data != node)
    {
        cout << node << " not found" << endl;
    }
    else
    {
        if (ptr == head)
        {
            deleteStart();
        }
        else if (ptr == tail)
        {
            deleteEnd();
        }
        else
        {
            Node *p_ptr = ptr->prev;
            p_ptr->next = ptr->next;
            p_ptr->next->prev = p_ptr;
            ptr->prev = ptr->next = NULL;
            free(ptr);
        }
    }
}

int main()
{
    head = tail = NULL;
    constructList(10);
    display();
    deleteStart();
    display();
    deleteEnd();
    display();
    deleteNode();
    display();
    deleteNode();
    display();
    deleteNode();
    display();
    return 0;
}