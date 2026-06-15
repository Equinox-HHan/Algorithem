#include<bits/stdc++.h>
using namespace std;
int FindPeakPosition(int arr[],int size)
{
    int l=0;int r=size-1;int mid=0;
    int ans=-1;
    if(size==0)
    {
        return ans;
    }
    else if(size==1)
    {
        return size; 
    }
    else
    {
        if(arr[0]>arr[1])
        {
            return 0;
        }
        else if(arr[size-2]>arr[size-1])
        {
            return size-1;
        }
        else
        {
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if(arr[mid-1]>arr[mid])
                {
                    r=mid-1;
                }
                else if(arr[mid+1]>arr[mid])
                {
                    l=mid+1;
                }
                else
                {
                    ans=mid;
                    break;
                }
            }
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