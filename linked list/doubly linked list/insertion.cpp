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

int getInput(string msg = "Enter node: ")
{
    int data;
    cout << msg;
    cin >> data;
    return data;
}

void display()
{
    if (isEmptyList())
    {
        cout << "List Empty" << endl;
    }
    else
    {
        Node *ptr = head;

        while (ptr != NULL)
        {
            cout << ptr->data << " <-> ";
            ptr = ptr->next;
        }
        cout << " NULL" << endl;
    }
}

void insertStart()
{
    int data = getInput();

    Node *ptr = new Node;
    ptr->data = data;
    ptr->prev = NULL;
    if (isEmptyList())
    {
        tail = ptr;
        ptr->next = NULL;
    }
    else
    {
        head->prev = ptr;
        ptr->next = head;
    }
    head = ptr;
}

void insertEnd()
{
    int data = getInput();

    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;
    if (isEmptyList())
    {
        head = ptr;
        ptr->prev = NULL;
    }
    else
    {
        tail->next = ptr;
        ptr->prev = tail;
    }
    tail = ptr;
}

void insertAfter()
{
    if (isEmptyList())
    {
        cout << "empty list" << endl;
        return;
    }

    int node = getInput("after? ");

    Node *flag = head;

    while (flag->data != node && flag->next != NULL)
    {
        flag = flag->next;
    }
    if (flag->data != node && flag->next == NULL)
    {
        cout << "node not found" << endl;
    }
    else
    {
        if (flag == tail)
        {
            insertEnd();
        }
        else
        {
            Node *ptr = new Node;
            int data = getInput();
            ptr->data = data;
            ptr->prev = flag;
            ptr->next = flag->next;
            flag->next = ptr;
        }
    }
}

void insertBefore()
{
    if (isEmptyList())
    {
        cout << "empty list" << endl;
        return;
    }

    int node = getInput("before? ");

    Node *flag = head;

    while (flag->data != node && flag->next != NULL)
    {
        flag = flag->next;
    }
    if (flag->data != node && flag->next == NULL)
    {
        cout << "node not found" << endl;
    }
    else
    {
        if (flag == head)
        {
            insertStart();
        }
        else
        {
            Node *ptr = new Node;
            int data = getInput();
            ptr->data = data;
            ptr->next = flag;
            ptr->prev = flag->prev;
            flag->prev->next = ptr;
            flag->prev = ptr;
        }
    }
}

int main()
{
    head = tail = NULL;

    cout << "################" << endl;
    cout << "1|Enter Start\n2|Enter End\n3|Enter After\n4|Enter Before\n0|Quit\nChoice > ";
    while (true)
    {
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertStart();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertAfter();
            break;
        case 4:
            insertBefore();
            break;
        case 0:
        {
            exit(0);
        }
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
        display();
        cout << "________________\n\nChoice > ";
    }

    return 0;
}