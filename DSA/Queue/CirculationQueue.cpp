#include<bits/stdc++.h>
using namespace std;
class CirculationQueue
{
    public:
    int *arr;
    int l;
    int r;
    int limit;
    int size;
    CirculationQueue(int n)
    {
        arr=new int[n];
        l=r=size=0;
        limit=n;
    }
    ~CirculationQueue()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return size==0;
    }
    bool isFull()
    {
        return size==limit;
    }
    void push(int x)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else
        {
            if(r==limit-1)
            {
                arr[r]=x;
                r=0;
            }
            else
            {
                arr[r++]=x;
            }
            size+=1;
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        {
            if(l==limit-1)
            {
                int number=arr[l];
                l=0;
                return number;
            }
            else
            {
                return arr[l++];
            }
            size-=1;
        }
    }
    int getHead()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        {
            return arr[l];
        }
    }
    int getTail()
    {
        if(r==0)
        {
            return arr[limit-1];
        }
        else
        {
            return arr[--r];
        }
    }
};

int main()
{
    CirculationQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.getHead()<<endl;
    cout<<q.getTail()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.getHead()<<endl;
    cout<<q.getTail()<<endl;
    return 0;
}
