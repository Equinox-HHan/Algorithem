#include<bits/stdc++.h>
using namespace std;
void InsertSort(int arr[],int size)
{
    if(arr==NULL||size<=1)
    {
        return;
    }
    for(int i=0;i<size-1;i++)//i<size
    {
        int minPosition=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
                minPosition=j;
                swap(arr[i],arr[minPosition]);
            }
        }
    }
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
    const int NUMBER=20;
    int arr[NUMBER];
    srand((unsigned)time(NULL));
    for(int i=0;i<NUMBER;i++)
    {
        arr[i]=rand()%100;
    }
    printArray(arr,NUMBER);
    InsertSort(arr,NUMBER);
    printArray(arr,NUMBER);   
    return 0;
}