#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int calculate(string str)
        {
            position=0;
            return func(str,0);
        }
    private:
        int position;
        //注意这里的全局变量
        //Java没有引用传递，cpp有引用传递
        //所以pos绑定指针后position是多余变量
        int func(const string &str,int pos)
        {
            int cur=0;
            vector<int> number;
            vector<char> ops;
            while(pos<str.length()&&str[pos]!=')')
            {
                if(str[pos]>='0'&&str[pos]<='9')//数字
                {
                    cur=cur*10+(str[pos]-'0');
                    pos+=1;
                }
                else if(str[pos]!='(')//加减乘除符号
                {
                    transfer(number,ops,cur,str[pos]);
                    cur=0;
                    pos+=1;
                }
                else//左小括号
                {
                    cur=func(str,pos+1);
                    pos=position+1;
                }
            }
            transfer(number,ops,cur,'+');
            position=pos;
            return compute(number,ops);
        }
        void transfer(vector<int> &number,vector<char> &ops,int cur,char op)
        //这个函数用于处理加减乘除关系
        //模拟出栈和压栈操作
        {
            if(ops.empty()||ops.back()=='+'||ops.back()=='-')
            {
                number.push_back(cur);
                ops.push_back(op);
            }
            else
            {
                int topNum=number.back();
                int topOp=ops.back();
                if(topOp=='*')
                {
                   number.back()=cur*topNum;
                }
                else
                {
                    number.back()=topNum/cur;
                }
                ops.back()=op;
            }
        }
        int compute(const vector<int> &number,const vector<char> &ops)
        //这个函数用于最后计算返回值
        {
            int ans=number[0];
            int n=number.size();
            for(int i=0;i<n-1;i++)
            {
                if(ops[i]=='+')
                {
                    ans+=number[i+1];
                }
                else
                {
                    ans-=number[i+1];
                }
            }
            return ans;
        }
};