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

void createCycle(node *&head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *temp1 = head;
    while (temp1->data != key)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1;
}

void breakCycle(node *&head)
{
    node *tortoise = head, *hare = head, *cycleBreak = head;

    while (hare->next != NULL && hare != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare)
        {
            while (tortoise->next != cycleBreak->next)
            {
                cycleBreak = cycleBreak->next;
                tortoise = tortoise->next;
            }
            cout << tortoise->next->data;
            tortoise->next = NULL;
            return;
        }
    }
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
}

int main()
{
    node *head = NULL;
    insertHead(head, 0);
    insertHead(head, 1);
    insertHead(head, 2);
    insertHead(head, 3);
    insertHead(head, 4);
    insertHead(head, 5);
    insertHead(head, 6);
    insertHead(head, 7);
    insertHead(head, 8);
    insertHead(head, 9);
    createCycle(head, 6);
    breakCycle(head);
    display(head);
}