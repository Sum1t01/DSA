// #include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void BSTinsertion(node *&root, int value)
{
    if (root == NULL)
    {
        root = new node(value);
        return;
    }

    if (value > root->data)
    {
        BSTinsertion(root->right, value);
    }
    else if (value < root->data)
    {
        BSTinsertion(root->left, value);
    }
    else
    {
        return;
    }
}

void inorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> S;
    node *current = root;

    while (current != NULL || S.empty() == false)
    {
        while (current != NULL)
        {
            S.push(current);
            current = current->left;
        }

        current = S.top();
        S.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void preorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> S;
    node *current = root;
    while (S.empty() == false || current != NULL)
    {
        while (current != NULL)
        {
            cout << current->data << " ";
            if (current->right!=NULL)
            {
                S.push(current->right);
            }
            current = current->left;
        }
        current = S.top();
        S.pop();
    }
}

void preorder1(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    node *temp = root;
    cout << temp->data << " ";
    preorder1(temp->left);
    preorder1(temp->right);
}

void BSTNodeSum(node* &root, int* &NodeSum)
{
    if(root==NULL)
    {
        return;
    }

    BSTNodeSum(root->left, NodeSum);
    *NodeSum+=root->data;
    BSTNodeSum(root->right, NodeSum);
}

void BSTNodeSum1(node* &root, int &NodeSum)
{
    if(root==NULL)
    {
        return;
    }

    BSTNodeSum1(root->left, NodeSum);
    NodeSum+=root->data;
    BSTNodeSum1(root->right, NodeSum);
}

int main()
{
    node *root = NULL;
    BSTinsertion(root, 3);
    BSTinsertion(root, 2);
    BSTinsertion(root, 4);
    BSTinsertion(root, 1);
    BSTinsertion(root, 5);
    inorder(root);
    int* NodeSum = new int;
    *NodeSum=0;
    BSTNodeSum(root, NodeSum);
    cout<<endl<<*NodeSum;
    int NodeSum1=0;
    BSTNodeSum1(root, NodeSum1);
    cout<<endl<<NodeSum1;
}