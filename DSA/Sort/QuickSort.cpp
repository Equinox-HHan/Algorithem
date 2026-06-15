#include<bits/stdc++.h>
using namespace std;
//三路划分，是传统随机快排变种
const int MAX=20;
int arr[MAX];
int First,Last;
void partion(int arr[],int l,int r,int x)
{
    First=l;
    Last=r;
    int i=l;
    while(i<=Last)
    {
        if(arr[i]==x)
        {
            i++;
        }
        else if(arr[i]<x)
        {
            swap(arr[i++],arr[First++]);
        }
        else
        {
            swap(arr[i],arr[Last--]);
        }
    }
}
void QuickSort(int arr[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int randomIndex=l+rand()%(r-l+1);
    int x=arr[randomIndex];
    partion(arr,l,r,x);
    int left=First;
    int right=Last;
    QuickSort(arr,l,left-1);
    QuickSort(arr,right+1,r);
}
void printArr(int arr[],int MAX)
{
    for(int i=0;i<MAX;i++)
    {
        cout<<setw(3);
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<MAX;i++)
    {
        arr[i]=rand()%100;
    }
    printArr(arr,MAX);
    QuickSort(arr,0,MAX-1);
    printArr(arr,MAX);
    return 0;
}