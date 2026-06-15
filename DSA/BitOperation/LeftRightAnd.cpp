#include<bits/stdc++.h>
using namespace std;
//计算左到右区间的按位与
int leftRightAnd(int left,int right)
{
    while(left<right)
    {
        right-=(right&-right);
    }
    return right;
}
int main()
{
    int left,right;
    cin>>left>>right;
    cout<<leftRightAnd(left,right)<<endl;
    return 0;
}