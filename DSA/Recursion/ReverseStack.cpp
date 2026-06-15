#include<bits/stdc++.h>
using namespace std;
//用递归实现反转栈
class Solution
{
    public:
        stack<int> Stack;
        void reverse(stack<int> &Stack)
        {
            if(Stack.empty())
            {
                return;
            }
            int temp=bottomTop(Stack);
            reverse(Stack);
            Stack.push(temp);
        }
    private:
        int bottomTop(stack<int> &Stack)
        {
            int number=Stack.top();
            if(Stack.empty())
            {
                return number;
            }
            int last=bottomTop(Stack);
            Stack.push(number);
            return last;
        }
};
int main()
{
    stack<int> Stack;
    Stack.push(1);
    Stack.push(2);
    Stack.push(3);
    Stack.push(4);
    Stack.push(5);
    Solution solution;
    solution.reverse(Stack);
    while(!Stack.empty())
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    return 0;
}