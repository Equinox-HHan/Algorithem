#include<bits/stdc++.h>
using namespace std;
//用异或的方式交换两个数
void swapExclusiveOr(int &a,int &b)
{
    a=a^b;
    b=b^a;
    a=a^b;
}
//正常交换两个数
void swapNormal(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a=10,b=20;
    cout<<"交换前a="<<a<<" b="<<b<<endl;
    swapExclusiveOr(a,b);
    cout<<"异或交换后a="<<a<<" b="<<b<<endl;
    a=10,b=20;
    swapNormal(a,b);
    cout<<"正常交换后a="<<a<<" b="<<b<<endl;
    return 0;
}