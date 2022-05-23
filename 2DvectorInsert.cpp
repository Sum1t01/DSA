#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> V;
    vector<int>W;

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            W.push_back(i);
        }
        V.push_back(W);
    }

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout<<V[j][i]<<" ";
        }
        cout<<endl;
    }
}