#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
int FinalArr[MAX];
int Arr[MAX];
void merge(int l,int r,int m)//自底向上合并
{
    int leftptr=l;
    int rightptr=m+1;
    int i=l;
    while(leftptr<=m&&rightptr<=r)
    {
        Arr[i++]=(FinalArr[leftptr]<=FinalArr[rightptr])?FinalArr[leftptr++]:FinalArr[rightptr++];
    }
    while(leftptr<=m)
    {
        Arr[i++]=FinalArr[leftptr++];
    }
    while(rightptr<=r)
    {
        Arr[i++]=FinalArr[rightptr++];
    }
    for(int k=l;k<=r;k++)
    {
        FinalArr[k]=Arr[k];
    }
}
void MergeSortRecursion(int l,int r)
{
    if(l==r)
    {
        return;
    }
    int m=l+(r-l)/2;
    MergeSortRecursion(l,m);
    MergeSortRecursion(m+1,r);
    merge(l,r,m);
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<MAX;i++)
    {
        FinalArr[i]=rand()%1000;
    }
    MergeSortRecursion(0,MAX-1);
    for(int i=0;i<MAX;i++)
    {
        cout<<left<<setw(5);
        cout<<FinalArr[i]<<" ";
        if((i+1)%10==0)
        {
            cout<<endl;
        }
    }
    return 0;
}
