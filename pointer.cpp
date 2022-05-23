#include<bits/stdc++.h>
#include <unistd.h>

using namespace std;

int main()
{
    int x=1;
    while(1)
    {
        system("cls");
        usleep(6000);
    cout << setw (75);
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7-i-1;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<=(2*i);k++)
        {
            cout<<"*";
        }
        for(int k=0;k<=(2*i-1);k++)
        {
            cout<<"#";
        }
        
        cout<<setw(75);
        cout<<endl;
    }
    }
}