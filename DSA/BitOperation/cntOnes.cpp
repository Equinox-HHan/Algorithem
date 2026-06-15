#include<bits/stdc++.h>
using namespace std;
//返回n的二进制表示中1的个数
unsigned int countOnes(unsigned int n)
{
    n = (n & 0x55555555) + ((n>>1) & 0x55555555);
	n = (n & 0x33333333) + ((n>>2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n>>4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n>>8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n>>16) & 0x0000ffff);
    return n;
}
int main()
{
    unsigned int n;
    cout<<"请输入一个整数：";
    cin>>n;
    cout<<n<<"的二进制表示中1的个数为:"<<countOnes(n)<<endl;
    return 0;
}