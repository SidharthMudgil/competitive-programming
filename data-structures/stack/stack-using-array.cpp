#include <iostream>
#include <limits>

using namespace std;

enum
{
    MAX_SIZE = 10
};

class Stack
{
    int top;
    int stack[MAX_SIZE];

    bool isEmpty();
    bool isFull();
    void peek();

public:
    Stack();
    void push();
    void pop();
    void change();
    void display();
};

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == MAX_SIZE;
}

void Stack::peek()
{
    if (isEmpty())
    {
        cout << "stack empty" << endl;
    }
    else
    {
        cout << "->" << stack[top] << endl;
    }
}

void Stack::push()
{
    if (isFull())
    {
        cout << "stack full" << endl;
    }
    else
    {
        int data;
        cout << "enter data: ";
        try
        {
            cin >> data;
            if (cin.fail())
                throw runtime_error("porn");
        }
        catch (const runtime_error e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> data;
        }
        top++;
        stack[top] = data;
    }
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "stack empty" << endl;
    }
    else
    {
        cout << stack[top] << " popped" << endl;
        top--;
    }
}

void Stack::change()
{
    if (isEmpty())
    {
        cout << "stack empty" << endl;
    }
    else
    {
        int pos;
        cout << "pos: ";
        cin >> pos;

        if (pos > top || pos < 0)
        {
            cout << "pos invalid" << endl;
        }
        else
        {
            int data;
            cout << "enter data: ";
            cin >> data;
            stack[pos] = data;
        }
    }
}

void Stack::display()
{
    if (isEmpty())
    {
        cout << "stack empty" << endl;
    }
    else
    {
        cout << "stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Stack s = Stack();
    s.display();
    s.push();
    s.display();
    s.push();
    s.display();
    s.push();
    s.display();
    s.push();
    s.display();
    s.push();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.change();
    s.display();

    return 0;
}