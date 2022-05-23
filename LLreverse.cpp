#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int key)
    {
        data = key;
        next = NULL;
    }
};

void insertHead(node *&head, int key)
{

    node *temp = new node(key);
    temp->next = head;
    head = temp;
    return;
}

void display(node *&head)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseLL(node *&head)
{
    node *previous = NULL, *current = head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

int main()
{
    node *head = NULL;
    insertHead(head, 7);
    insertHead(head, 0);
    insertHead(head, 8);
    insertHead(head, 9);
    insertHead(head, 5);
    insertHead(head, 6);
    display(head);
    reverseLL(head);
    display(head);
}