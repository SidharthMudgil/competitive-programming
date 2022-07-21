#include <iostream>

using namespace std;

#define MAX_SIZE 5

class Queue
{
    int queue[MAX_SIZE];
    int front;
    int rear;

    int get_data()
    {
        int data;
        cout << "data: ";
        cin >> data;
        return data;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return front == 0 && rear == MAX_SIZE - 1;
    }

public:
    Queue()
    {
        front = rear = -1;
    }
    void insert_front()
    {
        if (isFull())
        {
            cout << "queue full" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            queue[front] = get_data();
        }
        else if (front == 0)
        {
            cout << "no front space" << endl;
        }
        else
        {
            queue[--front] = get_data();
        }
    }
    void insert_rear()
    {
        if (isFull())
        {
            cout << "queue full" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
            queue[rear] = get_data();
        }
        else if (rear == MAX_SIZE - 1)
        {
            cout << "no rear space" << endl;
        }
        else
        {
            queue[++rear] = get_data();
        }
    }
    void delete_front()
    {
        if (isEmpty())
        {
            cout << "queue empty" << endl;
        }
        else if (front == rear)
        {
            cout << queue[front] << " deleted from start" << endl;
            front = rear = -1;
        }
        else
        {
            cout << queue[front] << " deleted from start" << endl;
            front++;
        }
    }
    void delete_rear()
    {
        if (isEmpty())
        {
            cout << "queue empty" << endl;
        }
        else if (front == rear)
        {
            cout << queue[rear] << " deleted from end" << endl;
            front = rear = -1;
        }
        else
        {
            cout << queue[rear] << " deleted from end" << endl;
            rear--;
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
            cout << "queue: ";
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    Queue q = Queue();
    q.insert_front();
    q.display();
    q.insert_rear();
    q.display();
    q.delete_rear();
    q.display();
    q.delete_front();
    q.display();
    q.delete_rear();
    q.display();
    return 0;
}