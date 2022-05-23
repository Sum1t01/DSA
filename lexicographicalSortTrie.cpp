#include <bits/stdc++.h>

using namespace std;

class trieNode
{
public:
    vector<trieNode *> children;
    bool is_end;

    trieNode()
    {
        children.resize(26, NULL);
        is_end = false;
    }
};

void insert(trieNode *&root, string s)
{
    trieNode *temp = root;
    for (char a : s)
    {
        if (!temp->children[a - 'a'])
        {
            temp->children[a - 'a'] = new trieNode();
        }
        temp = temp->children[a - 'a'];
    }
    temp->is_end = true;
}

void display(trieNode *&root, string s = "")
{
    // if(root==NULL)
    // {
    //     return;
    // }
    if (root->is_end)
    {
        cout << s << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            char c = 'a' + i;
            display(root->children[i], s + c);
        }
    }
}

int main()
{
    trieNode *root = new trieNode();
    vector<string> container = {"abc", "xy", "bcd", "xyz", "x"};
    for (string a : container)
    {
        insert(root, a);
    }
    display(root);
}