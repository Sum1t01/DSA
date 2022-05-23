#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insertatHead(node *&head, int x)
{
    node *newHead = new node(x);
    if (head == NULL)
    {
        head = newHead;
        return;
    }
    newHead->next = head;
    head = newHead;
    return;
}

void displayNode(node *&head)
{
    if (head == NULL)
    {
        cout << "empty node";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

void insertatTail(node *&head, int x)
{
    node *newTail = new node(x);
    if (head == NULL)
    {
        head = newTail;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newTail;
    return;
}

void deleteHead(node *&head)
{
    node *temp = head;
    head = temp->next;
    delete temp;
    return;
}

void deleteTail(node *&head)
{
    node *temp = head;
    node *last;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
        last = temp->next;
    }
    temp->next = NULL;
    delete last;
    return;
}

int listLength(node *&head)
{
    int a = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        a++;
    }
    return a;
}

int main()
{
    node *head = NULL;
    insertatHead(head, 0);
    insertatHead(head, 1);
    insertatHead(head, 2);
    insertatTail(head, -1);
    //deleteHead(head);
    //deleteTail(head);
    displayNode(head);
    cout << endl
         << "The number of elements in the list is: " << listLength(head) << endl;
    return 0;
}
