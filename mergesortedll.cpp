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

node *mergeLinkedList(node *&list1, node *&list2)
{
    node *temp = new node(0), *temp1 = NULL;
    temp1 = temp;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    // if (list1 == NULL)
    // {
    //     temp->next = list2;
    // }
    // else
    // {
    //     temp->next = list1;
    // }
    temp->next=(list1==NULL)?list2:list1;
    return temp1->next;
}
/*          
            2->3->5->7->9->11->12->13
            1->4->7->10
            2->3->4->5->7->7->9->10->11->12->13
*/
int main()
{
    node *l1 = NULL, *l2 = NULL;
    insertHead(l1, 13);
    insertHead(l1, 12);
    insertHead(l1, 11);
    insertHead(l1, 9);
    insertHead(l1, 7);
    insertHead(l1, 5);
    insertHead(l1, 3);
    insertHead(l1, 2);
    display(l1);
    insertHead(l2, 10);
    insertHead(l2, 7);
    insertHead(l2, 4);
    insertHead(l2, 1);
    display(l2);
    node *l3 = mergeLinkedList(l1, l2);
    display(l3);
}