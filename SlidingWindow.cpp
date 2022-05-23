#include<bits/stdc++.h>

using namespace std;

int slidingWindow(vector<int> &V,  int k)
{
    int sliding_sum=0;
    
    for(int i=0;i<k;i++)
    {
        sliding_sum+=V[i];
    }

    int max_sum=sliding_sum;
    for(int i=k;i<V.size();i++)
    {
        sliding_sum+=V[i]-V[i-k];
        max_sum=max(max_sum,sliding_sum);
    }
    return max_sum;
}

int main()
{
    vector<int>V={1, 4, 2, 10, 2, 3, 1, 0, 20};
    cout<<slidingWindow(V,4);
}