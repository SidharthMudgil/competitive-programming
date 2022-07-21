#include <iostream>
#include <limits>

using std::cin;
using std::cout;

struct Queue
{
    int data;
    Queue *next;
} * rear, *front;

int get_input()
{
    int data;
    cout << "data: ";
    try
    {
        cin >> data;
        if (cin.fail())
            throw std::runtime_error("bawligand interger daal na");
        else
            return data;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return get_input();
    }
}

bool is_empty()
{
    return front == NULL;
}

bool is_full()
{
    Queue *ptr = new Queue();
    return ptr == NULL;
}

void enqueue()
{
    Queue *ptr = new Queue();
    ptr->data = get_input();

    if (is_empty())
        front = ptr;
    else
        rear->next = ptr;
    ptr->next = front;
    rear = ptr;
}

void dequeue()
{
    if (is_empty())
    {
        cout << "queue empty"
             << "\n";
    }
    else if (rear == front)
    {
        cout << front->data << " deleted"
             << "\n";
        rear = front = NULL;
    }
    else
    {
        cout << front->data << " deleted"
             << "\n";
        Queue *temp = front;

        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    if (is_empty())
    {
        cout << "queue empty"
             << "\n";
    }
    else
    {
        Queue *ptr = front;
        cout << "queue: ";
        while (ptr->next != front)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data << "\n\n";
    }
}

int main()
{
    front = rear = NULL;
    enqueue();
    display();
    enqueue();
    display();
    dequeue();
    return 0;
}