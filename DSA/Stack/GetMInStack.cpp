#include<bits/stdc++.h>
#include"Stack.h"
using namespace std;
//用STL栈实现
class GetMinStack1
{
    public:
        GetMinStack1(){}
        void push(int x)
        {
            collectStack.push(x);
            if(minStack.isEmpty()||x<=minStack.pop())
            {
                minStack.push(x);
            }
            else
            {
                minStack.push(minStack.pop());
            }
        }
        int getMin()
        {
            return minStack.peek();
        }
        void popOut()
        {
            collectStack.pop();
            minStack.pop(); 
        }
        void peekOut()
        {
            collectStack.peek();
        }
    private:
        Stack1 collectStack;
        Stack1 minStack;
};
//用数组实现
class GetMinStack2
{
    public:
        GetMinStack2()
        {
            Size=0;
        }
        void push(int x)
        {
            if(Size>=MAX)
            {
                cout<<"Stack Overflow"<<endl;
                return;
            }
            else
            {
                arr[Size]=x;
                if(Size==0||minArr[Size-1]>=x)
                {
                    minArr[Size]=x;
                }
                else
                {
                    minArr[Size]=minArr[Size-1];
                }
                Size+=1;
            }
        }
        void popOut()
        {
            if(Size<=0)
            {
                cout<<"Stack Underflow"<<endl;
                return;
            }
            else
            {
                Size-=1;
            }
        }
        int getMin()
        {
            if(Size<=0)
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else
            {
                return minArr[Size-1];
            }
        }
        int peekOut()
        {
            if(Size<=0)
            {
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else
            {
                return arr[Size-1];
            }
        }
    private:
        static const int MAX=100;
        int arr[MAX];
        int minArr[MAX];
        int Size;
};

int main()
{
    GetMinStack1 s1;
    s1.push(3);
    s1.push(5);
    cout<<s1.getMin()<<endl;
    s1.push(2);
    s1.push(1);
    cout<<s1.getMin()<<endl;
    s1.popOut();
    cout<<s1.getMin()<<endl;
    s1.popOut();
    cout<<s1.getMin()<<endl;
    GetMinStack2 s2;
    s2.push(3);
    s2.push(5);
    cout<<s2.getMin()<<endl;
    s2.push(2);
    s2.push(1);
    cout<<s2.getMin()<<endl;
    s2.popOut();
    cout<<s2.getMin()<<endl;
    s2.popOut();
    cout<<s2.getMin()<<endl;
    return 0;
}
