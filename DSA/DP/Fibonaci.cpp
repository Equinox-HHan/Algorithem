#include<bits/stdc++.h>
using namespace std;
//最基础的递归版斐波那契
int fib1(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fib1(n-1)+fib1(n-2);
}
//带备忘录的递归
int fib2(int n)
{   
    int arr[n+1];
    memset(arr,sizeof(arr),-1);
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    int ans=fib2(n-1)+fib2(n-2);
    arr[n]=ans;
    return ans;
}
//自底向上DP
int fib3(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}//空间优化的DP
int fib4(int n)
{
    if(n==1)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    int cur=1,pre=0;
    int now;
    for(int i=2;i<=n;i++)
    {
        now=cur+pre;
        pre=cur;
        cur=now;
    }
    return now;
}
