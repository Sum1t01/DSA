#include<bits/stdc++.h>

using namespace std;

void display(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int &x, int &y)
{
    int temp=x;
    x=y;
    y=temp;
}


void DNF2(int * arr, int size)
{
    int low=0,high=size-1;
    while(low<high)
    {
        if(arr[low]==1)
        {
            swap(arr[low],arr[high]);
            high--;
        }
        else
        {
            low++;
        }
    }
}

void DNF(int *arr, int size)
{
    int low=0,mid=0,high=size-1;
    while(mid<=high)
    {
        switch(arr[mid])
        {
            case 0:
            {
                swap(arr[low],arr[mid]);
                low++;
                mid++;
                break;
            }
            case 1:
            {
                mid++;
                break;
            }
            case 2:
            {
                swap(arr[mid],arr[high]);
                high--;
                break;
            }

        }
    }
}

int main()
{
    int arr[10]={1,0,2,1,1,1,2,0,0,0};
    int arr2[10]={0,1,1,1,0,1,0,0,1,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr2,size);
    DNF2(arr2,size);
    display(arr2,size);

}
