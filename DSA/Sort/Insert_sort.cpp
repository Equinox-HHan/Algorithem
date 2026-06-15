#include<bits/stdc++.h>
using namespace std;
void InsertSort(int arr[],int size)
{
    if(arr==NULL||size<=1)
    {
        return;
    }
    for(int i=1;i<size;i++)//i=0
    {
        for (int j=i-1; j>=0&&arr[j]>arr[j+1];j--)
        {
            swap(arr[j],arr[j+1]);
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