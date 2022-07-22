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

bool isSingleNode()
{
    return head == tail;
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

void deleteStart()
{
    if (isEmptyList())
    {
        cout << "list empty" << endl;
    }
    else if (isSingleNode())
    {
        cout << head->data << " deleted from start" << endl;
        Node *ptr = head;
        head = tail = NULL;
        free(ptr);
    }
    else
    {
        Node *ptr = head;
        cout << head->data << " deleted from start" << endl;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        free(ptr);
    }
}

void deleteEnd()
{
    if (isEmptyList())
    {
        cout << "list empty" << endl;
    }
    else if (isSingleNode())
    {
        cout << head->data << " deleted from end" << endl;
        Node *ptr = head;
        head = tail = NULL;
        free(ptr);
    }
    else
    {
        Node *ptr = tail;
        cout << tail->data << " deleted from end" << endl;
        tail = tail->prev;
        head->prev = tail;
        tail->next = head;
        free(ptr);
    }
}

void deleteNode(int node)
{
    if (isEmptyList())
    {
        cout << "list empty" << endl;
    }
    else
    {
        Node *ptr = head;

        while (ptr->data != node && ptr->next != head)
        {
            ptr = ptr->next;
        }

        if (ptr->data != node)
        {
            cout << "node not found" << endl;
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
                Node *toDelete = ptr;
                cout << ptr->data << " deleted" << endl;
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                ptr->next = ptr->prev = NULL;
                free(toDelete);
            }
        }
    }
}

int main()
{
    head = tail = NULL;
    constructList();
    display();
    deleteStart();
    display();
    deleteStart();
    display();
    deleteEnd();
    display();
    deleteEnd();
    display();
    deleteNode(7);
    display();
    deleteNode(2);
    display();
    deleteNode(9);
    display();
    return 0;
}