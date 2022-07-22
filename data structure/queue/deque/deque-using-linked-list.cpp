#include <iostream>

using namespace std;

struct Queue
{
    int data;
    Queue *next;
} * front, *rear;

bool isFull()
{
    Queue *ptr = new Queue;
    return ptr == NULL;
}

bool isEmpty()
{
    return front == NULL;
}

int getData()
{
    int data;
    cout << "data: ";
    cin >> data;
    return data;
}

void insertFront()
{
    if (isFull())
    {
        cout << "queue full" << endl;
    }
    else
    {
        Queue *ptr = new Queue;
        ptr->data = getData();
        if (isEmpty())
        {
            ptr->next = NULL;
            front = rear = ptr;
        }
        else
        {
            ptr->next = front;
            front = ptr;
        }
    }
}

void insertEnd()
{
    if (isFull())
    {
        cout << "queue full" << endl;
    }
    else
    {
        Queue *ptr = new Queue;
        ptr->data = getData();
        ptr->next = NULL;
        if (isEmpty())
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}

void deleteStart()
{
    if (isEmpty())
    {
        cout << "queue empty" << endl;
    }
    else if (front == rear)
    {
        cout << front->data << " deleted from start" << endl;
        front = rear = NULL;
    }
    else
    {
        Queue *ptr = front;
        cout << front->data << " deleted from start" << endl;
        front = front->next;
        free(ptr);
    }
}

void deleteEnd()
{
    if (isEmpty())
    {
        cout << "queue empty" << endl;
    }
    else if (front == rear)
    {
        cout << rear->data << " deleted from end" << endl;
        front = rear = NULL;
    }
    else
    {
        Queue *ptr = front;
        Queue *temp = rear;
        while (ptr->next != rear)
        {
            ptr = ptr->next;
        }
        cout << rear->data << " deleted from end" << endl;
        ptr->next = NULL;
        rear = ptr;
        free(temp);
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
        Queue *ptr = front;

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
    front = rear = NULL;
    insertFront();
    display();
    insertEnd();
    display();
    insertEnd();
    display();
    deleteStart();
    display();

    return 0;
}