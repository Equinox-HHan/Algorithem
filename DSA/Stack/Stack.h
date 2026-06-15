#ifndef STACK_H
#define STACK_H

#include<bits/stdc++.h>
using namespace std;
//Stack的STL实现
class Stack1
{
    public:
        stack<int> s;
        void push(int x)
        {
            s.push(x);
        }
        int pop()
        {
            if(s.empty())
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else
            {
                int x=s.top();
                s.pop();
                return x;
            }
        }
        int peek()
        {
            if(s.empty())
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else
            {
                cout<<s.top()<<endl;
                return s.top();
            }
        }
        int size()
        {
            return s.size();
        }
        bool isEmpty()
        {
            return s.empty();
        }
};
//Stack的数组实现
class Stack2
{
    public:
        int size;
        int limit;
        int *arr;
        Stack2(int n)
        {
            arr=new int[n];
            size=0;
            limit=n;
        }
        ~Stack2()
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
                cout<<"Stack is Full"<<endl;
                return;
            }
            else
            {
                arr[size++]=x;
            }
        }
        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            else
            {
                return arr[--size];
            }
        }
        int peek()
        {
            if(isEmpty())
            {
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            else
            {
                cout<<arr[size-1]<<endl;
                return arr[size-1];
            }
        }
        int getSize()
        {
            return size;
        }
};
#endif