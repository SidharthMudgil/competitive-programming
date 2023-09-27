#include <iostream>
#include <limits>

using namespace std;

enum
{
    MAX_SIZE = 10
};

class Queue
{
    int queue[MAX_SIZE];
    int front;
    int rear;

    bool is_queue_empty()
    {
        return front == -1 || front > rear;
    }
    bool is_queue_full()
    {
        return rear == MAX_SIZE - 1;
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

        queue[++rear] = get_data();
    }

    void dequeue()
    {
        if (is_queue_empty())
            cout << "queue empty" << endl;

        else
        {
            cout << queue[front++] << " deleted" << endl;
        }
    }

    void display()
    {
        if (is_queue_empty())
            cout << "queue empty" << endl;

        else
        {
            cout << "queue: ";
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl << endl;
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