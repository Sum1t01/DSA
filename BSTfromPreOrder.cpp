#include<bits/stdc++.h>

using namespace std;

class node
{
    public:
    int data;
    node* left, * right;
    node(int key)
    {
        data=key;
        left=right=NULL;
    }
};

void inorder(node* &root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorderBST(node* &root, vector<int> &array, int low, int high)
{
    if(low>high)
    {
        return;
    }
    root=new node(array[low]);
    if(low==high)     
    {
        return;
    }
    /*      Not keeping the above conditional statement 
            causes heap overflow in Leetcode. Find out why. 
    */

    int i;
    for(i = low+1;array[i]<array[low];i++)
    {

    }
    preorderBST(root->left,array, low+1, i-1);
    preorderBST(root->right,array, i, high);
}

int main()
{
    vector<int>array={4,2,1,3,5,7};
    int low=0,high=array.size()-1;
    node* root=NULL;
    preorderBST(root,array, low, high);
    inorder(root);
}