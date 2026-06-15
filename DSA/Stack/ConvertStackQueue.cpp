#include<bits/stdc++.h>
#include"Stack.h"
using namespace std;
//用双栈实现队列：STL栈
class StackConvertQueue
{
    public:
        StackConvertQueue(){}
        void Transfer()
        {
            if(Outstack.isEmpty())
            {
                while(!Instack.isEmpty())
                {
                    int number=Instack.pop();
                    Outstack.push(number);
                }
            }
        }
        void pushIn(int x)
        {
            Instack.push(x);
            Transfer();
        }
        int popOut()
        {
            Transfer();
            return Outstack.pop();
        }
        int peekOut()
        {
            Transfer();
            return Outstack.peek();
        }

    private:
        Stack1 Instack;
        Stack1 Outstack;
};
//用双栈实现队列：数组栈
class StackConvertQueue2
{
    public:
        StackConvertQueue2(int n):Instack(n),Outstack(n)
        {
        }
        void Transfer()
        {
            if(Outstack.isEmpty())
            {
                while(!Instack.isEmpty())
                {
                    int number=Instack.pop();
                    Outstack.push(number);
                }
            }
        }
        void pushIn(int x)
        {
            Instack.push(x);
            Transfer();
        }
        int popOut()
        {
            Transfer();
            return Outstack.pop();
        }
        int peekOut()
        {
            Transfer();
            return Outstack.peek();
        }
    private:
        Stack2 Instack;
        Stack2 Outstack;
};

int main()
{
    StackConvertQueue queue1;
    queue1.pushIn(1);
    queue1.pushIn(2);
    queue1.pushIn(3);
    cout<<queue1.popOut()<<endl;
    cout<<queue1.peekOut()<<endl;
    StackConvertQueue2 queue2(10);
    queue2.pushIn(1);
    queue2.pushIn(2);
    queue2.pushIn(3);
    cout<<queue2.popOut()<<endl;
    cout<<queue2.peekOut()<<endl;
    return 0;
}