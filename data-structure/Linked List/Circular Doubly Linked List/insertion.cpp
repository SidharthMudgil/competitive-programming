#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int data;
} * head, *tail;

int getInput(string msg = "data? ")
{
    int data;
    try
    {
        cout << msg;
        cin >> data;
        if (cin.fail())
        {
            throw new runtime_error("only integer value allowed");
        }
        return data;
    }
    catch (const runtime_error e)
    {
        cout << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return getInput(msg);
    }
}

bool isEmptyList()
{
    return head == NULL;
}

void insertFirst()
{
    Node *ptr = new Node;
    int data = getInput();
    ptr->data = data;
    if (isEmptyList())
    {
        ptr->next = ptr;
        ptr->prev = ptr;
        tail = ptr;
    }
    else
    {
        head->prev = ptr;
        ptr->next = head;
        ptr->prev = tail;
        tail->next = ptr;
    }
    head = ptr;
}

void insertEnd()
{
    Node *ptr = new Node;
    int data = getInput();
    ptr->data = data;
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

void insertAfter(int node)
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
            if (ptr == tail)
            {
                insertEnd();
            }
            else
            {
                Node *n_ptr = new Node;
                n_ptr->data = getInput();
                n_ptr->prev = ptr;
                n_ptr->next = ptr->next;
                ptr->next->prev = n_ptr;
                ptr->next = n_ptr;
            }
        }
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

int main()
{
    head = tail = NULL;
    insertFirst();
    display();
    insertFirst();
    display();
    insertEnd();
    display();
    insertEnd();
    display();
    insertAfter(1);
    display();
    insertAfter(6);
    display();
    insertAfter(10);
    display();
    return 0;
}