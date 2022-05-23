// #include<bits/stdc++.h>

// using namespace std;

// void climber(int n, int *counter)
// {
//     if(n<0)
//     {
//         return;
//     }
//     else if(n==0)
//     {
//         *counter+=1;
//     }
//     climber(n-1,counter);
//     climber(n-2,counter);
// }

// int main()
// {
//     int total=0;
//     int *counter=&total;
//     climber(44,counter);
//     cout<<total;
// }

#include<bits/stdc++.h>

using namespace std;

int climber(int* array, int n)
{
    if(array[n]!=0)
    {
        return array[n];
    }
    array[n]=climber(array,n-1)+climber(array,n-2);
    return array[n];
}

int main()
{
    int array[46];
    memset(array,0,sizeof(array));
    array[0]=0;
    array[1]=1;
    array[2]=2;
    cout<<climber(array, 44);
}