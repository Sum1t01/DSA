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

void insertHead(node *&head, int key)
{
    node *temp = new node(key);
    temp->next = head;
    head = temp;
}

node *middle(node *&low, node *&high)
{
    if (low == NULL)
    {
        return NULL;
    }
    node *slowpointer = low, *fastpointer = low;
    while (fastpointer != high && fastpointer->next != NULL)
    {
        slowpointer = slowpointer->next;
        fastpointer = fastpointer->next->next;
    }
    return slowpointer;
}

bool BinarySearch(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    node *low = head, *high = NULL, *mid = NULL;
    do
    {
        mid = middle(low, high);
        if (mid == NULL)
        {
            return false;
        }
        else if (mid->data == key)
        {
            return true;
        }
        else if (key > mid->data)
        {
            low = mid->next;
        }
        else
        {
            high = mid;
        }
    } while (low != high && high != NULL);
    return false;
}

int main()
{
    node *head = NULL;
    insertHead(head, 10);
    insertHead(head, 9);
    insertHead(head, 8);
    insertHead(head, 7);
    insertHead(head, 6);
    insertHead(head, 5);
    insertHead(head, 4);
    insertHead(head, 3);
    insertHead(head, 2);
    insertHead(head, 1);
    display(head);
    cout << BinarySearch(head, 7);
}