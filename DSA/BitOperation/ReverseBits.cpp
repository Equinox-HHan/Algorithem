#include<bits/stdc++.h>
using namespace std;
//反转二进制位
unsigned int ReverseBits(unsigned int n)
{
    n=((n&0x55555555)<<1)|((n&0xAAAAAAAA)>>1);
    n=((n&0x33333333)<<2)|((n&0xCCCCCCCC)>>2);
    n=((n&0x0F0F0F0F)<<4)|((n&0xF0F0F0F0)>>4);
    n=((n&0x00FF00FF)<<8)|((n&0xFF00FF00)>>8);
    n=(n<<16)|(n>>16);
    return n;
}
int main()
{
    unsigned int n;
    cin>>n;
    cout<<bitset<32>(n)<<endl;
    cout<<ReverseBits(n)<<endl;
    return 0;
}