#include<bits/stdc++.h>
using namespace std;
//找到数组中只出现一次的数字
int singleNumber(int arr[],int n)
{
    int ExclusiveOr=0;
    for(int i=0;i<n;i++)
    {
        ExclusiveOr=ExclusiveOr^arr[i];
    }
    return ExclusiveOr;
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
    cout<<singleNumber(arr,n)<<endl;
    return 0;
}