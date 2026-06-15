#include<bits/stdc++.h>
using namespace std;
//一个数字是否是2的幂次方
bool PowerofTwo(int n)
{
    return n>0&&n==(n&-n);
}
int main()
{
    int n;
    cin>>n;
    if(PowerofTwo(n))
        cout<<n<<" is a power of two."<<endl;
    else
        cout<<n<<" is not a power of two."<<endl;
    return 0;
}