#ifndef QUEUE_H
#define QUEUE_H

#include<bits/stdc++.h>
using namespace std;
//Queue的STL实现
class Queue1
{
    public:
        queue<int> q;
        bool isEmpty()
        {
            return q.empty();
        }
        int size()
        {
            return q.size();
        }
        void offer(int x)
        {
            q.push(x);
        }
        int peek()
        {
            if(q.empty())
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else
            {
                cout<<q.front()<<endl;
                return q.front();
            }
        }
        int poll()
        {
            if(q.empty())
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else
            {
                int x=q.front();
                q.pop();
                return x;
            }
        }
};
//Queue的数组实现
class Queue2
{
    public:
        int l;
        int r;
        int *arr;
        Queue2(int n)
        {
            arr=new int[n];
            l=r=0;
        }
        ~Queue2()
        {
            delete[] arr;
        }
        bool isEmpty()
        {
            return l==r;
        }
        int size()
        {
            return r-l;
        }
        void offer(int x)
        {
            arr[r++]=x;
        }
        int peek()
        {
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            else
            {
                cout<<arr[l]<<endl;
                return arr[l];
            }
        }
        int poll()
        {
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return -1;
            }
            else
            {
                return arr[l++];
            }    
        }
};
#endif