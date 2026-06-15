#include<bits/stdc++.h>
using namespace std;
//找到最接近的2的幂次方
int near2Power(int n)
{
    if(n<=0)
    {
        return 1;
    }
    (unsigned)n--;
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;
    return n+1;
}
int main()
{
    int n;
    cin>>n;
    cout<<near2Power(n)<<endl;
    return 0;
}