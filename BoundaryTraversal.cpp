#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int val;
    node *left, *right;

    node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

void printLeft(node *&root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    cout << root->val << " ";
    printLeft(root->left);
}

void printRight(node *&root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    printRight(root->right);
    cout << root->val << " ";
}

void printLeaves(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->val << " ";
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printBoundary(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    printLeft(root);
    printLeaves(root);
    printRight(root->right);
    cout<<endl;
}

int main()
{
    node *root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right = new node(22);
    root->right->right = new node(25);

    node* root1=new node(1);
    root1->left=new node(2);
    root1->left->left= new node(4);
    root1->left->right= new node(9);
    root1->left->left->left= new node(6);
    root1->left->left->right= new node(5);
    root1->left->right->right= new node(3);
    root1->left->right->right->left= new node(7);
    root1->left->right->right->right= new node(8);

    printBoundary(root);
    printBoundary(root1);

    return 0;
}