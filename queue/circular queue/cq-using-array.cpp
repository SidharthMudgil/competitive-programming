#include <iostream>
#include <limits>

using namespace std;

enum
{
    MAX_SIZE = 5
};

class Queue
{
    int queue[MAX_SIZE];
    int front;
    int rear;

    bool is_queue_empty()
    {
        return front == -1;
    }
    bool is_queue_full()
    {
        return (rear == MAX_SIZE - 1 && front == 0) || rear == front - 1;
    }

    int get_data()
    {
        int data;
        cout << "data: ";
        try
        {
            cin >> data;
            if (cin.fail())
                throw runtime_error("invalid input (\"only integers allowed\")");
            return data;
        }
        catch (const runtime_error e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return get_data();
        }
    }

public:
    Queue()
    {
        front = rear = -1;
    }

    void enqueue()
    {
        if (is_queue_empty())
            front++;

        else if (is_queue_full())
        {
            cout << "queue full" << endl;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = get_data();
    }

    void dequeue()
    {
        if (is_queue_empty())
            cout << "queue empty" << endl;

        else
        {
            cout << queue[front] << " deleted" << endl;
            front = (front + 1) % MAX_SIZE;

            if (front == rear)
                front = rear = -1;
        }
    }

    void display()
    {
        if (is_queue_empty())
            cout << "queue empty" << endl;

        else
        {
            cout << "queue: ";
            if (front > rear)
            {
                for (int i = front; i < MAX_SIZE; i++)
                    cout << queue[i] << " ";

                for (int i = 0; i <= rear; i++)
                    cout << queue[i] << " ";
            }
            else
            {
                for (int i = front; i <= rear; i++)
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
    q.enqueue();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}