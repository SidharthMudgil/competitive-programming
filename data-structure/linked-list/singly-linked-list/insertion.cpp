#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * head;

int getInput()
{
    int data;
    cout << "data: ";
    cin >> data;

    return data;
}

bool isFirstNode()
{
    return head == NULL;
}

void insertStart()
{
    int data = getInput();

    Node *ptr = new Node;
    isFirstNode() ? ptr->next = NULL : ptr->next = head;
    ptr->data = data;
    head = ptr;
}

void insertEnd()
{
    int data = getInput();

    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;
    if (isFirstNode())
    {
        head = ptr;
    }
    else
    {
        Node *t_ptr = head;

        while (t_ptr->next != NULL)
        {
            t_ptr = t_ptr->next;
        }
        t_ptr->next = ptr;
    }
}

void insertAfter()
{
    int node;

    cout << "After Node: ";
    cin >> node;

    Node *ptr = new Node;
    Node *t_ptr = head;

    while (t_ptr->data != node && t_ptr->next != NULL)
    {
        t_ptr = t_ptr->next;
    }
    if (t_ptr->data == node)
    {
        if (t_ptr->next == NULL)
        {
            insertEnd();
        }
        else
        {
            int data = getInput();
            ptr->next = t_ptr->next;
            t_ptr->next = ptr;
            ptr->data = data;
        }
    }
    else
    {
        cout << "Node not found" << endl;
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
    cout << "################" << endl;
    cout << "1|Enter Start\n2|Enter End\n3|Enter After\n0|Quit\nChoice > ";
    while (true)
    {
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertStart();
            display();
            break;
        case 2:
            insertEnd();
            display();
            break;
        case 3:
            if (head != NULL)
            {
                insertAfter();
                display();
            }
            else
                cout << "List Empty" << endl;
            break;
        case 0:
        {
            display();
            exit(0);
        }
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << "________________\n" << endl;
        cout << "Choice > ";
    }
    return 0;
}