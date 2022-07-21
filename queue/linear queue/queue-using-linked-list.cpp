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
        front = rear = ptr;
    else
        rear->next = ptr;

    ptr->next = NULL;
    rear = ptr;
}

void dequeue()
{
    if (is_empty())
    {
        cout << "queue empty"
             << "\n";
    }
    else
    {
        Queue *ptr = front;
        cout << ptr->data << " deleted"
             << "\n";
        Queue *temp = ptr;

        ptr = ptr->next;
        front = ptr;
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
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n\n";
    }
}

int main()
{
    front = rear = NULL;
    enqueue();
    display();
    dequeue();
    display();
    return 0;
}