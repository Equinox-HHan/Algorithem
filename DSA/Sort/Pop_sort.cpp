#include<bits/stdc++.h>
using namespace std;
void PopSort(int arr[],int size)
{
    if(arr==NULL||size<=1)
    {
        return;
    }
    for(int i=size-1;i>0;i--)//i=size
    {
        for(int j=0;j<size;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
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
    PopSort(arr,NUMBER);
    printArray(arr,NUMBER);
    return 0;
}