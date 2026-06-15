#include<bits/stdc++.h>
using namespace std;
//三路划分，荷兰国旗问题
//快速选择，最终结果不一定全部有序
int First,Last;
const int MAX=20;
int arr[MAX];
void partation(int arr[],int l,int r,int x)
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
            swap(arr[i],arr[First]);
            i++;
            First++;
        }
        else
        {
            swap(arr[i],arr[Last]);
            Last--;
        }
    }
}
int RandomSelect(int arr[],int i)
{
    srand((unsigned)time(NULL));
    int ans=0;
    for(int l=0,r=MAX-1;l<=r;)
    {
        int randomIndex=l+rand()%(r-l+1);
        int x=arr[randomIndex];
        partation(arr,l,r,x);
        if(i<First)
        {
            r=First-1;
        }
        else if(i>Last)
        {
            l=Last+1;
        }
        else
        {
            ans=arr[i];
            break;
        }
    }
    return ans;
}
void printArr()
{
    for(int i=0;i<MAX;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<MAX;i++)
    {
        arr[i]=rand()%20;
    }
    printArr();
    cout<<RandomSelect(arr,10)<<endl;
    printArr();
    sort(arr,arr+MAX);
    printArr();
    return 0;
}