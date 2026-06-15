#include<bits/stdc++.h>
using namespace std;
int findMissNumber(int arr[],int n)
{
    int xorAll=0;
    int xorHas=0;
    //一共有n+1个数，0~n，缺失一个数，所以数组长度为n
    for(int i=0;i<n;i++)
    {
        xorAll^=i;
        xorHas^=arr[i];
    }
    //最后还要把n加入到xorAll中
    xorAll^=n;
    return xorAll^xorHas;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<findMissNumber(arr,n)<<endl;
    return 0;
}