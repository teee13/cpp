#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
void delete_last(Node **head)
{
    Node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (ptr->next == nullptr)
        {
            ptr->prev->next = NULL;
        }
    }
}
void delete_before(Node **head, int pos)
{
    Node *ptr = *head;
    int i = 1;
    while (i <= pos)
    {
        i++;
        ptr = ptr->next;
        if (i == pos)
        {
            ptr->prev->prev->next = ptr;
            delete (ptr->prev);
        }
    }
}
void insert_front(Node **head, int val, Node *h)
{
    Node *new_val = new Node();
    new_val->data = val;
    new_val->next = *head;
    new_val->prev = NULL;
    h->prev = new_val;
    *head = new_val;
}
void insert_end(int val, Node **h)
{
    Node *new_val = new Node();

    Node *ptr = *h;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        if (ptr->next == nullptr)
        {
            new_val->data = val;
            new_val->prev = ptr;
            ptr->next = new_val;
            new_val->next = nullptr;
        }
    }
}
void show(Node **head)
{
    Node *ptr = *head;
    while (ptr != nullptr)
    {
        cout << ptr->data << "\n";
        ptr = ptr->next;
    }
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    head->data = 1;
    head->next = second;
    head->prev = NULL;
    second->data = 2;
    second->prev = head;
    second->next = third;
    third->data = 3;
    third->prev = second;
    third->next = NULL;
    cout << "enter which function you want to see?\n 1.insert at front\tinsert at the end\tdelete from the end\tdelete before a given node\n";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        insert_front(&head, 0, head);
        cout << "0 inserted at front\n";
        show(&head);

        break;
    case 2:
        cout << " inserted at the end\n";
        insert_end(4, &head);
        show(&head);
        break;
    case 3:
        cout << "last node deleted\n";
        delete_last(&head);
        show(&head);
        break;
    case 4:
        cout << "deleting before 3rd node---\n";
        delete_before(&head, 3);
        show(&head);
        break;

    label:
        cout << "invalid input\n";
    }

    return 0;
}
