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

bool isSingleNode()
{
    return head->next == NULL;
}

bool isOperatinApplicable()
{
    if (isListEmpty())
    {
        cout << "List Empty";
        return false;
    }
    else if (isSingleNode())
    {
        cout << head->data << " deleted";
        head = NULL;
        return false;
    }
    return true;
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

void deleteStart()
{
    if (isOperatinApplicable())
    {
        Node *ptr = head;
        cout << head->data << " deleted";
        head = head->next;
        free(ptr);
    }
}

void deleteEnd()
{
    if (isOperatinApplicable())
    {
        Node *t_ptr;
        Node *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        t_ptr = ptr->next;
        ptr->next = NULL;
        cout << t_ptr->data << " deleted";
        free(t_ptr);
    }
}

void deleteNode()
{
    int node;
    cout << "Enter Node: ";
    cin >> node;

    if (head->data != node)
    {
        Node *ptr = head;
        while (ptr->next != NULL && ptr->next->data != node)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL && ptr->data != node)
        {
            cout << "Node not found";
        }
        else
        {
            Node *t_ptr = ptr->next;
            ptr->next = ptr->next->next;
            cout << t_ptr->data << " deleted";
            free(t_ptr);
        }
    }
    else
    {
        deleteStart();
    }
}

void display()
{
    cout << "\nList: ";

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
    constructList();
    display();
    cout << "\n################" << endl;
    cout << "1|Delete Start\n2|Delete End\n3|Delete Node\n0|Quit\nChoice > ";
    while (true)
    {
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            deleteStart();
            display();
            break;
        case 2:
            deleteEnd();
            display();
            break;
        case 3:
            if (head != NULL)
            {
                deleteNode();
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
        cout << "\n________________\n" << endl;
        cout << "Choice > ";
    }
    return 0;
}