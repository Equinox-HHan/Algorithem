#include<bits/stdc++.h>
using namespace std;
//分治二分搜索
bool DichotomySearch(int arr[],int size,int number)
{
    if(size==0||arr==NULL)
    {
        return false;
    }
    int l=0;int r=size-1;int mid=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]>number)
        {
            r=mid-1;
        }
        else if(arr[mid]<number)
        {
            l=mid+1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    const int number=21;
    const int size=20;
    int arr[size];
    srand((unsigned)time(NULL));
    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%100;
    }
    sort(arr,arr+size);
    printArray(arr,size);
    if(DichotomySearch(arr,size,number))
    {
        cout<<"Found "<<number<<endl;
    }
    else
    {
        cout<<"Not Found "<<number<<endl;
    }
    return 0;
}