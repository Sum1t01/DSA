#include<bits/stdc++.h>

using namespace std;

int main()
{
int array[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int* turtle=array, * rabbit=array, * print=array;

// rabbit+=2;
while(rabbit<=&array[15])
{
turtle++;
rabbit+=2;
}
// cout<<*(--turtle);
while(print<turtle)
{
cout<<*print<<" ";
print++;
}
cout<<endl;
rabbit--;
while(print<rabbit)
{
cout<<*print<<" ";
print++;
}
return 0;
}
