#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node* right, * down;

    node( int key)
    {
        data=key;
        right=down=NULL;
    }
};

void display(node* &head)
[
    if(head==NULL)
    {
        return;
    }
]