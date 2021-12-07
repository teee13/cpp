#include <iostream>
using namespace std;
#define max 50
int rear = -1;
int front = -1;
int queue[max];
int is_mpty()
{
    int empty = 0;
    if (front == -1 || front == rear + 1)
        empty = 1;

    return empty;
}

int is_full()
{
    int full = 0;
    if (rear == max - 1)
        full = 1;
    return full;
}

void enqueue(int data)
{
    if (is_full())
    {
        cout << "OVERFLOW!!!!! \n";
    }
    if (front == -1)
    {
        rear = 0;
        front = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (is_mpty())
    {
        cout << "NOTHING TO DELETE \n";
        return;
    }
    else
        front++;
}

void peek()
{
    while (front != rear + 1)
    {
        cout << queue[front] << "\n";
        front++;
    }
}

int main()
{
    int ch;
    int val;
    while (ch != 0)
    {
        cout << "enter what you want finction you want to perform on the queue\n 1. insert \n 2. delete \n 3. peek\n press 0to exit ";
        cin >>
            ch;
        switch (ch)
        {
        case 1:
            cout << "enter value to insert";
            cin >> val;
            enqueue(val);

            break;
        case 2:
            dequeue();

            break;
        case 3:
            peek();
            break;
        label:
            cout << "invalid choice";
        }
    }

    return 0;
}
