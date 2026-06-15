#include<bits/stdc++.h>
using namespace std;
int FindMinPosition(int arr[],int size,int number)
{
    int l=0;int r=size-1;int mid=0;
    int ans=-1;
    if(arr==NULL||size==0)
    {
        return ans;
    }
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(arr[mid]>=number)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
int FindMaxPosition(int arr[],int size,int number)
{
    int l=0;int r=size-1;int mid=0;
    int ans=-1;
    if(arr==NULL||size==0)
    {
        return ans;
    }
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(arr[mid]<=number)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
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
    int minPos=FindMinPosition(arr,size,number);
    int maxPos=FindMaxPosition(arr,size,number);
    cout<<"Min Position of "<<number<<" is: "<<minPos<<"("<<minPos+1<<")"<<endl;
    cout<<"Max Position of "<<number<<" is: "<<maxPos<<"("<<maxPos+1<<")"<<endl;
    return 0;
}