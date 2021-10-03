#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

int empty(Node *head)
{
    if (head->next == NULL)
        return 1;
    else
        return 0;
}
void create_list(Node *head)
{
    int i = 1, n;
    int val;
    Node *tail = new Node();
    cout << "enter number of nodes";
    cin >> n;
    while (i <= n)
    {
        if (i == 1)
        {
            cin >> val;
            head->data = val;
            head->next = NULL;
        }
        else if (i == 2)
        {
            cin >> val;

            head->next = tail;
            tail->data = val;
            tail->next = NULL;
        }
        else
        {
            cin >> val;
            Node *new_node = new Node();
            tail->next = new_node;
            new_node->data = val;
            new_node->next = NULL;
        }
        i++;
    }
}

void show(Node *ptr)
{

    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
}
void insertAtfront(Node **head)
{
    int val;
    cout << "value:";
    cin >> val;
    Node *newval = new Node();
    newval->data = val;
    newval->next = *head;
    *head = newval;
}
void insertAtend(Node **head)
{

    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
        if (last->next == NULL)
        {
            int val;
            cout << "value:";
            cin >> val;
            Node *newval = new Node();
            newval->data = val;
            last->next = newval;
            newval->next = NULL;
            last = newval;
        }
    }
}
void insertAtpos(Node **head)
{
    Node *pos = *head;
    cout << "enter postion after which you want to insert new node";
    int p;
    cin >> p;
    for (int i = 1; i < p; i++)
    {
        pos = pos->next;
        if (i == p - 1)
        {
            int val;
            cout << "value:";
            cin >> val;
            Node *newval = new Node();
            newval->data = val;
            Node *temp;
            temp = pos->next;
            pos->next = newval;
            newval->next = temp;
        }
    }
}

int main()
{
    Node *head = new Node();
    head->next = NULL;
    int n, q;
    cout << "how many queries?";
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        if (empty(head))
        {
            create_list(head);
        }
        else
        {
            cout << "press 1 to insert at front \n press 2 to insert after a node \n press three to insert at the end";
            cin >> n;
            if (n == 1)
                insertAtfront(&head);
            else if (n == 2)
                insertAtpos(&head);
            else
                insertAtend(&head);
        }
        show(head);
    }
    return 0;
}