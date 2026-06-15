#include<bits/stdc++.h>
using namespace std;
const int MAX=100;
int FinalArr[MAX];
int Arr[MAX];
void merge(int l,int r,int m)
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
void MergeSort()
{
    for(int step=1;step<MAX;step<<=1)
    {
        int l=0;
        while(l<MAX)
        {
            int m=l+step-1;
            if(m>=MAX-1)
            {
                break;
            }
            int r=min(MAX-1,l+(step<<1)-1);
            merge(l,r,m);
            l=r+1;
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<MAX;i++)
    {
        FinalArr[i]=rand()%1000;
    }
    MergeSort();
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