/*
    O(n) -> Time  Complexity
    O(1) -> Space Complexity (Auxiliary)
*/

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

void reverseK(node *&head, int k)
{
    int i = 0;
    node *previous = NULL, *current = head, *next = NULL;
    while (i < k)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        i++;
    }

    // display(previous);
    // node *temp = previous;

    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = current;

    head->next=current;
    head = previous;
}

int main()
{
    node *head = NULL;
    insertHead(head, 9);
    insertHead(head, 8);
    insertHead(head, 7);
    insertHead(head, 6);
    insertHead(head, 5);
    insertHead(head, 4);
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);
    insertHead(head, 0);
    display(head);
    reverseK(head, 5);
    display(head);
}