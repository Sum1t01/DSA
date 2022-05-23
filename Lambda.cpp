#include <bits/stdc++.h>

using namespace std;

bool comp(int i, int j)
{
    return abs(i)<abs(j);
}


void heap_demo()
{
    auto comp= [](pair<int,int>a,pair<int,int>b)->bool
    {
        return a.first==b.first?a.second<b.second:a.first>b.first;
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(comp)>p(comp);
    p.push({1,2});
    p.push({1,3});
    p.push({2,3});

    auto m=p;
    while(!m.empty())
    {
        cout<<m.top().first<<" "<<m.top().second<<endl;
        m.pop();
    }
}

int main()
{
    vector<int> v = {1, -24, 6, -3, 37, 8, -11};
    // sort(v.begin(), v.end(), [](int i, int j) -> bool
    //      { return j > i; });

    // sort(v.begin(), v.end(), [](int a, int b)
    //      { return abs(a) > abs(b); });

    // sort(v.begin(), v.end(), comp);
    // for (int a : v)
    // {
    //     cout << a << " ";
    // }
    heap_demo();
}