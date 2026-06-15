#include<bits/stdc++.h>
using namespace std;
const int MAX=20;
int arr[MAX];
void HeapInsert(int arr[],int i)//向上交换大根堆实现
{
    while(arr[i]>arr[(i-1)/2])
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void Heapify(int arr[],int i,int HeapSize)//向下交换大根堆实现
{
    int leftson=(i*2)+1;
    while(leftson<HeapSize)
    {
        int best=(leftson+1<HeapSize&&arr[leftson]<arr[leftson+1])?leftson+1:leftson;
        best=(arr[best]>arr[i])?best:i;
        if(best==i)
        {
            break;
        }
        swap(arr[best],arr[i]);
        i=best;
        leftson=(i*2)+1;
    }
}
//void Heapify2.0(int i,int heapSize)
//{
//    int leftson=(i*2)+1;
//    int rightson=(i*2)+2;
//    if(leftson>heapSize-1)
//    {
//        return;  
//    }
//    int bestson=leftson;
//    if(rightson<MAX&&arr[leftson]<arr[rightson])
//    {
//         bestson=rightson;
//    }
//    if(arr[bestson]<=arr[i])    
//    {    
//        return;  
//    }        
//    swap(arr[i],arr[bestson]);    
//    Heapify2.0(bestson,heapSize);
//}
void HeapSort()
{
    for(int i=MAX-1;i>=0;i--)
    {
        Heapify(arr,i,MAX);
    }
    //for(int i=0;i<MAX;i++)
    //{
    //    HeapInsert(arr,i)
    //}
    int number=MAX;
    while(number>0)
    {
        swap(arr[0],arr[--number]);
        Heapify(arr,0,number);
    }
}
void printArr()
{
    for(int i=0;i<MAX;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<MAX;i++)
    {
        arr[i]=rand()%100;
    }
    printArr();
    HeapSort();
    printArr();
    return 0;
}