#include<bits/stdc++.h>
using namespace std;
int FindPeakPosition(int arr[],int size)
{
    //修复之前存在的逻辑问题
    if(arr==nullptr||size<=0)
    {
        return -1;
    }
    int l=0,r=size-1;
    while(l<r)
    {
        int mid=l+((r-l)>>1);//位运算优先度是低于加减运算的
        if(arr[mid]>arr[mid+1])
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
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
    const int NUMBER=10;
    int arr[NUMBER];
    srand((unsigned)time(NULL));
    for(int i=0;i<NUMBER;i++)
    {
        arr[i]=rand()%100;
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    int peakPosition=FindPeakPosition(arr,size);
    if(peakPosition!=-1)
    {
        cout<<"Peak element found at index: "<<peakPosition<<endl;
        cout<<"Peak element is: "<<arr[peakPosition]<<endl;
    }
    else
    {
        cout<<"No peak element found."<<endl;
    }
    return 0;
}