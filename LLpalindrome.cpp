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

bool isPalindrome(node *&head)
{
    // if(head==NULL || head->next==NULL)
    // {
    //     return true;
    // }

    // if(head->next->next==NULL)
    // {
    //     if(head->data==head->next->data)
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    node *slowPointer = head, *fastPointer = head->next;

    while (fastPointer != NULL && fastPointer->next != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }

    node *firstSubList = head, *secondSubList = slowPointer->next;
    slowPointer->next = NULL;

    node *previous = NULL, *current = secondSubList, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    secondSubList = previous;

    bool flag = true;

    display(firstSubList);
    display(secondSubList);
    while (firstSubList != NULL && secondSubList != NULL)
    {
        if (firstSubList->data != secondSubList->data)
        {
            flag = false;
            break;
        }
        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }

    return flag;
}

int main()
{
    node *head = NULL;
    insertHead(head, 1);
    insertHead(head, 2);
    insertHead(head, 3);
    // insertHead(head,3);
    insertHead(head, 2);
    insertHead(head, 1);
    display(head);
    cout << isPalindrome(head);
}