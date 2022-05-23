#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next, * previous;
    node(int x)
    {
        data = x;
        next = NULL;
	previous = NULL;
    }
};

void insertNode(node* &head, int value)
{
    node *newNode = new node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
    return;
};

void listSplit(node *&head, node *&frontHead, node *&backHead)
{
    	node* rabbit= head, * turtle=head;
	frontHead=head;
	// rabbit=rabbit->next->next;
	while(rabbit!=NULL && rabbit->next!=NULL)
	{
	turtle=turtle->next;
	rabbit=rabbit->next->next;
	}
	backHead=turtle;
	turtle=turtle->previous;
	turtle->next=NULL;
}

void displayNode(node *&head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
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

int main()
{
    node *head = NULL;
    insertNode(head, 0);
    insertNode(head, 9);
    insertNode(head, 8);
    insertNode(head, 7);
    insertNode(head, 6);
    insertNode(head, 5);
    insertNode(head, 4);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);
    cout << "The Nodes of the Linked List are: " << endl;
    displayNode(head);
    node *frontHead = NULL, *backHead = NULL;
    listSplit(head, frontHead, backHead);
    cout << endl
         << "After Splitting: " << endl
         << "Front Sub-list: " << endl;
    displayNode(frontHead);
    cout << "Back Sub-list: " << endl;
    displayNode(backHead);
    return 0;
}