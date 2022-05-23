#include<bits/stdc++.h>

using namespace std;

void BucketSort(vector<int>&V)
{
    vector<int>bucket(11,0);
    for(int a:V)
    {
        bucket[a]++;
    }
    int index=0;
    for(int i=0;i<bucket.size();i++)
    {
        for(int j=0;j<bucket[i];j++)
        {
            V[index]=i;
            index++;
        }
    }
}

int main()
{
    vector<int>V={1,4,5,2,8,9,10,1,1,0,5,8,3,9,0,1,2,3,5,5,5};
    BucketSort(V);
    for(int a:V)
    {
        cout<<a<<" ";
    }
    return 0;
}