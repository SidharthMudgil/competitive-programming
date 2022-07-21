#include <iostream>

using namespace std;

struct Stack
{
    int data;
    Stack *next;
} * top;

bool isEmpty()
{
    return top == NULL;
}

void push()
{
    int data;
    Stack *node = new Stack();
    cout << "enter data: ";
    cin >> data;
    node->data = data;
    if (isEmpty())
    {
        node->next = NULL;
    }
    else
    {
        node->next = top;
    }
    top = node;
}

void pop()
{
    if (isEmpty())
    {
        cout << "list empty" << endl;
    }
    else
    {
        cout << top->data << " popped" << endl;
        Stack *toDelete = top;
        top = top->next;
        free(toDelete);
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "list empty" << endl;
    }
    else
    {
        Stack *ptr = top;

        cout << "stack: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main()
{
    top = NULL;
    push();
    display();
    push();
    display();
    push();
    display();
    push();
    display();
    push();
    display();
    push();
    display();
    push();
    display();
    pop();
    display();
    pop();
    display();

    return 0;
}