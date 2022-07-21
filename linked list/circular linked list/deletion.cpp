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

bool isSingleNode()
{
    return head->next == head;
}

int getInput(string msg = "which? ")
{
    cout << msg;
    int data;
    try
    {
        cin >> data;
        if (cin.fail())
            throw runtime_error("Invalid input");
    }
    catch (const runtime_error err)
    {
        cout << err.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return getInput(msg);
    }
    return data;
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

void constructList(int size = 10)
{
    for (int i = size; i >= 1; i--)
    {
        Node *ptr = new Node;
        ptr->data = i;
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
}

void deleteStart()
{
    if (isListEmpty())
    {
        cout << "list empty" << endl;
    }
    else if (isSingleNode())
    {
        cout << head->data << " deleted from start" << endl;
        head = NULL;
    }
    else
    {
        cout << head->data << " deleted from start" << endl;

        Node *ptr = head;
        Node *toDelete = head;

        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        head = head->next;
        ptr->next = head;
        free(toDelete);
    }
}

void deleteEnd()
{
    if (isListEmpty())
    {
        cout << "list empty" << endl;
    }
    else if (isSingleNode())
    {
        cout << head->data << " deleted from end" << endl;
        head = NULL;
    }
    else
    {
        Node *ptr = head;
        Node *toDelete = head;

        while (ptr->next->next != head)
        {
            ptr = ptr->next;
        }

        cout << ptr->next->data << " deleted from end" << endl;

        toDelete = ptr->next;
        ptr->next = head;
        free(toDelete);
    }
}

void deleteNode()
{
    if (isListEmpty())
    {
        cout << "list empty" << endl;
    }
    else
    {
        int node = getInput();

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
            if (ptr == head)
            {
                deleteStart();
            }
            else if (ptr->next == head)
            {
                deleteEnd();
            }
            else
            {
                Node *p_node = head;

                while (p_node->next->data != node && p_node->next != head)
                {
                    p_node = p_node->next;
                }

                cout << p_node->next->data << " deleted" << endl;

                Node *toDelete = p_node->next;
                p_node->next = ptr->next;
                free(toDelete);
            }
        }
    }
}

int main()
{
    head = NULL;
    constructList();
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
    deleteNode();
    display();
    deleteNode();
    display();

    return 0;
}