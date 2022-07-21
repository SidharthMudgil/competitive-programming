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

int getInput(string msg)
{
    cout << msg;
    int data;
    // handle exception
    try
    {
        cin >> data;
        if (cin.fail())
        {
            throw runtime_error("Invalid input");
        }
        return data;
    }
    catch (const runtime_error err)
    {
        cout << err.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return getInput(msg);
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

void insertStart()
{
    Node *ptr = new Node;
    ptr->data = getInput("enter data: ");

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

void insertEnd()
{
    Node *ptr = new Node;
    ptr->data = getInput("enter data: ");

    if (isListEmpty())
    {
        ptr->next = ptr;
        head = ptr;
    }
    else
    {
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = ptr;
        ptr->next = head;
    }
}

void insertAfter()
{
    int node = getInput("after? ");

    Node *ptr = head;
    while (ptr->data != node && ptr->next != head)
    {
        ptr = ptr->next;
    }
    if (ptr->data != node && ptr->next == head)
    {
        cout << "node not found" << endl;
    }
    else
    {
        if (ptr->next == head)
        {
            insertEnd();
        }
        else
        {
            Node *n_ptr = new Node;
            n_ptr->data = getInput("enter data: ");
            n_ptr->next = ptr->next;
            ptr->next = n_ptr;
        }
    }
}

int main()
{
    head = NULL;
    insertStart();
    display();
    insertStart();
    display();
    insertEnd();
    display();
    insertEnd();
    display();
    insertAfter();
    display();
    insertAfter();
    display();
    insertAfter();
    display();
    return 0;
}