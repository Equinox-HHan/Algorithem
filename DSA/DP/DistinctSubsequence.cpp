#include<bits/stdc++.h>
using namespace std;
//不同子序列数问题，可以不连续
class Solution
{
    public:
        int solve()
        {
            cin>>str;
            return func(str);
        }
    private:
        string str;
        const static int mod=1000000007;
        int func(string str)
        {
            int ans=1,newadd=0;
            int count[26];
            memset(count,sizeof(count),0);
            for(char x:str)
            {
                newadd=(ans-count[x-'a']+mod)%mod;
                count[x-'a']=(count[x-'a']+newadd)%mod;
                ans=(ans+newadd)%mod;
            }
            return (ans-1+mod)%mod;
        }
};