#include<bits/stdc++.h>
using namespace std;
const int MAX=10;
int arr[MAX];
int ass[MAX];
int merge(int l,int r,int m)
{
    int ans=0;
    int sum=0;
    for(int i=l,j=m+1;j<=r;j++)
    {
        while(i<=m&&arr[i]<=arr[j])
        {
            sum+=arr[i++];
        }
        ans+=sum;
    }
    int leftptr=l;
    int rightptr=m+1;
    int i=l;
    while(leftptr<=m&&rightptr<=r)
    {
        ass[i++]=(arr[leftptr]<=arr[rightptr])?arr[leftptr++]:arr[rightptr++];
    }
    while(leftptr<=m)
    {
        ass[i++]=arr[leftptr++];
    }
    while(rightptr<=r)
    {
        ass[i++]=arr[rightptr++];
    }
    for(int i=l;i<=r;i++)
    {
        arr[i]=ass[i];
    }
    return ans;
}
int smallSum(int l,int r)
{
    if(l==r)
    {
        return 0;
    }
    int m=(l+r)/2;
    return smallSum(l,m)+smallSum(m+1,r)+merge(l,r,m);
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<MAX;i++)
    {
        arr[i]=rand()%10;
    }
    for(int i=0;i<MAX;i++)
    {
        cout<<left<<setw(5);
        cout<<arr[i]<<" ";
        if((i+1)%10==0)
        {
            cout<<endl;
        }
    }
    cout<<smallSum(0,MAX-1)<<endl;
    return 0;
}