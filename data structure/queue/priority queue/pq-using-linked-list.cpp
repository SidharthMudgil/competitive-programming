#include <iostream>

using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;
} * head;

bool isEmpty()
{
    return head == NULL;
}

bool isFull()
{
    return new Node == NULL;
}

pair<int, int> getInput()
{
    pair<int, int> node;

    int data;
    int priority;

    cout << "data: ";
    cin >> data;

    cout << "priority: ";
    cin >> priority;

    node.first = data;
    node.second = priority;

    return node;
}

void add()
{
    if (isFull())
    {
        cout << "queue full" << endl;
    }
    else
    {
        Node *ptr = new Node;
        pair<int, int> pr = getInput();
        ptr->data = pr.first;
        ptr->priority = pr.second;

        if (isEmpty() || ptr->priority < head->priority)
        {
            ptr->next = head;
            head = ptr;
        }
        else
        {
            Node *prev = head;

            while (prev->next != NULL && prev->next->priority <= ptr->priority)
            {
                prev = prev->next;
            }

            ptr->next = prev->next;
            prev->next = ptr;
        }
    }
}

void poll()
{
    if (isEmpty())
    {
        cout << "queue empty" << endl;
    }
    else
    {
        Node *ptr = head;
        cout << ptr->data << " deleted with priority " << ptr->priority << endl;
        head = head->next;
        free(ptr);
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "queue empty" << endl;
    }
    else
    {
        Node *ptr = head;
        cout << "queue: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl
             << endl;
    }
}

int main()
{
    head = NULL;

    add();
    display();
    add();
    display();
    add();
    display();
    add();
    display();
    add();
    poll();
    display();
    return 0;
}