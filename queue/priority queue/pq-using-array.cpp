#include <iostream>

using namespace std;

#define MAX 10

struct item
{
    int data;
    int priority;
};

class Queue
{
private:
    int index;
    item queue[MAX];

    bool isFull() { return index == MAX - 1; }
    bool isEmpty() { return index == MAX - 1; }

    template <typename T>
    pair<T, T> get_input()
    {
        pair<T, T> itm;

        int data;
        int priority;

        cout << "data: ";
        cin >> data;

        cout << "priority: ";
        cin >> priority;

        itm.first = data;
        itm.second = priority;

        return itm;
    }

public:
    Queue() { index = -1; }

    void add()
    {
        if (isFull())
        {
            cout << "queue full" << endl;
        }
        else
        {
            pair<int, int> itm = get_input<int>();
            index++;

            queue[index].data = itm.first;
            queue[index].priority = itm.second;
        }
    }

    int peek()
    {
        int pos = -1;
        int max_priority = INT_MAX;

        for (int i = 0; i < index; i++)
        {
            if (queue[i].priority == max_priority && pos > -1 && queue[i].data < queue[pos].data)
            {
                max_priority = queue[i].priority;
                pos = i;
            }
            else if (queue[i].priority < max_priority)
            {
                max_priority = queue[i].priority;
                pos = i;
            }
        }

        return pos;
    }

    void poll()
    {
        if (isEmpty())
        {
            cout << "queue empty" << endl;
        }
        else
        {
            int i, pos = peek();

            cout << pos << " ";

            cout << queue[pos].data << " deleted with priority " << queue[pos].priority << endl;

            for (i = pos; i < MAX - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            queue[i].data = -1;
            queue[i].priority = INT_MAX;
            index--;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "queue emptty" << endl;
        }
        else
        {
            cout << "queue: ";
            for (int i = 0; i <= index; i++)
            {
                cout << queue[i].data << " ";
            }
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    Queue q = Queue();
    q.add();
    q.display();
    q.add();
    q.poll();
    q.display();

    return 0;
}
