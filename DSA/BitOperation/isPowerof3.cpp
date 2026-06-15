#include<bits/stdc++.h>
using namespace std;
//判断一个数是否是3的幂
bool PowerofThree(int n)
{
    return n>0&&1162261467%n==0;
}
int main()
{
    int n;
    cin>>n;
    if(PowerofThree(n))
        cout<<n<<" is a power of three."<<endl;
    else
        cout<<n<<" is not a power of three."<<endl;
    return 0;
}