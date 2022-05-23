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

void OddEvenSum(node *&l1, node *&l2, node *&l3)
{
    if (l1->next->next == NULL)
    {
        l2 = NULL;
        l3 = NULL;
        return;
    }
    int OddSum = l1->data;
    int EvenSum = l1->next->data;
    l2 = new node(0);
    l3 = new node(0);
    node *odd = l1, *even = l1->next, *temp2 = l2, *temp3 = l3;

    while (odd->next->next != NULL && even->next != NULL)
    {
        odd = odd->next->next;
        OddSum += odd->data;
        l2->next = new node(OddSum);
        OddSum = odd->data;
        l2 = l2->next;
        even = even->next->next;
        EvenSum += even->data;
        l3->next = new node(EvenSum);
        EvenSum = even->data;
        l3 = l3->next;
    }
    l2 = temp2->next;
    l3 = temp3->next;
}

int main()
{
    node *l1 = NULL, *l2 = NULL, *l3 = NULL;
    // insertHead(l1, 8);
    // insertHead(l1, 7);
    insertHead(l1, 6);
    insertHead(l1, 5);
    insertHead(l1, 4);
    insertHead(l1, 3);
    insertHead(l1, 2);
    insertHead(l1, 1);
    display(l1);
    OddEvenSum(l1, l2, l3);
    display(l2);
    display(l3);
}