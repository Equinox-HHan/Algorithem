#include<bits/stdc++.h>
using namespace std;
int add(int a,int b)
{
    int ans=a;
    while(b!=0)
    {
        ans=a^b;
        b=(a&b)<<1;
        a=ans;
    }
    return ans;
}
int neg(int number)
{
    return (~number+1);
}
int mminus(int a,int b)
{
    return add(a,neg(b));
}
int multi(int a,int b)
{
    int ans=0;
    while(b!=0)
    {
        if((b&1)==1)
        {
            ans=add(ans,a);
        }
        a<<=1;
        b=(unsigned int)b;
        b>>=1;
    }
    return ans;
}
int divide(int a,int b)
{
    int ans=0;
    int x=a>0?a:neg(a);
    int y=b>0?b:neg(b);
    for(int i=30;i>=0;i=mminus(i,1))
    {
        if((x>>i)>=y)
        {
            ans|=(1<<i);
            x=mminus(x,y<<i);
        }
    }
    return (a<0)^(b<0)?neg(ans):ans;
}
const int MIN=INT_MIN;
int Divide(int a,int b)
{
    if(a==MIN&&b==MIN)
    {
        return 1;
    }
    if(b==MIN)
    {
        return 0;
    }
    if(a!=MIN&&b!=MIN)
    {
        return divide(a,b);
    }
    if(a==MIN&&b==neg(1))
    {
        return INT_MAX;
    }
    a=add(a,b<0?neg(b):b);
    int ans=divide(a,b);
    int offset=b>0?neg(1):1;
    return add(ans,offset);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<add(a,b)<<endl;
    cout<<mminus(a,b)<<endl;
    cout<<multi(a,b)<<endl;
    cout<<divide(a,b)<<endl;
    cout<<Divide(a,b)<<endl;
    return 0;
}