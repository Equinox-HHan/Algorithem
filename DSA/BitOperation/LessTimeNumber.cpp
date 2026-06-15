#include<bits/stdc++.h>
using namespace std;
//每个数字出现了m次，只有一个数字出现了k次，找出这个数字
int findLesstimeNumber(int arr[],int n,int m,int k)
{
    int cnts[32]={0};
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        for(int k=0;k<32;k++)
        {
            cnts[k]+=(num>>k)&1;
        }
    }
    int ans=0;
    for(int i=0;i<32;i++)
    {
        if(cnts[i]%m!=0)
        {
            ans|=(1u<<i);
        }
    }
    return ans;
}
int main()
{
    int arr[]={1,1,1,2,2,2,3,3,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m=3;
    int k=1;
    cout<<findLesstimeNumber(arr,n,m,k)<<endl;
    return 0;
}