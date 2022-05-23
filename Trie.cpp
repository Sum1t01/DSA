#include <bits/stdc++.h>

using namespace std;

class trieNode
{
public:
    vector<trieNode *> children;
    bool isEndofWord;

    trieNode()
    {
        children.resize(26, NULL);
        isEndofWord = false;
    }
};

void insert(trieNode *&root, string a)
{
    trieNode *temp = root;

    for (int i = 0; i < a.size(); i++)
    {
        if (!temp->children[a[i] - 'a'])
        {
            temp->children[a[i] - 'a'] = new trieNode();
        }
        temp = temp->children[a[i] - 'a'];
    }
    temp->isEndofWord = true;
}

void display(trieNode *&root, string s="")
{
    // if(root==NULL)
    // {
    //     return;
    // }
    if (root->isEndofWord == true)
    {
        cout<<s<<endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            char m = 'a' + i;
            display(root->children[i],s+m);
        }
    }
    
}

int main()
{
    trieNode *root = new trieNode();
    insert(root, "gupta");
    insert(root, "guptaa");
    insert(root, "gupat");
    insert(root, "guptaaaaa");
    display(root);
}