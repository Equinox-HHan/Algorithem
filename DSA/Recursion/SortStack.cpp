#include<bits/stdc++.h>
using namespace std;
//用递归实现栈排序
class Solution
{
    public:
        stack<int> Stack;
        void mainFunction(stack<int> &Stack)
        {
            int deep=Deep(Stack);
            while(deep>0)
            {
                int max=getMax(Stack,deep);
                int k=times(Stack,deep,max);
                maxDown(Stack,deep,max,k);
                deep-=k;
            }
        }
    private:
        int Deep(stack<int> &Stack)
        {
            if(Stack.empty())
            {
                return 0;
            }
            int temp=Stack.top();
            Stack.pop();
            int deep=Deep(Stack)+1;
            Stack.push(temp);
            return deep;
        }
        int getMax(stack<int> &Stack,int deep)
        {
            if(Stack.empty())
            {
                return INT_MIN;
            }
            int temp=Stack.top();
            Stack.pop();
            int maxNumber=getMax(Stack,deep-1);
            Stack.push(temp);
            return max(temp,maxNumber);
        }
        int times(stack<int> &Stack,int deep,int max)
        {
            if(Stack.empty())
            {
                return 0;
            }
            int temp=Stack.top();
            Stack.pop();
            int restTime=times(Stack,deep-1,max);
            int time=restTime+(temp==max?1:0);
            Stack.push(temp);
            return time;
        }
        void maxDown(stack<int> &Stack,int deep,int max,int k)
        {
            if(deep==0)
            {
                for(int i=0;i<k;i++)
                {
                    Stack.push(max);
                }
            }
            else
            {
                int num=Stack.top();
                Stack.pop();
                maxDown(Stack,deep-1,max,k);
                if(num!=max)
                {
                    Stack.push(num);
                }
            }
        }
};
int main()
{
    return 0;
}