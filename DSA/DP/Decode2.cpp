#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void solve(string str)
        {
            recursionDP.assign(str.size()+1,INT_MAX);
            dp.assign(str.size()+1,-1);
            recursion(str,0);
            recursion_dp(str,0);   
            DP(str);
        }
    private:
        vector<int> recursionDP;
        vector<long long> dp;
        const static int mod=100000007;
        int recursion(string str,int i)//最暴力的递归不取模
        {
            if(i==str.size())
            {
                return 1;
            }
            if(str[i]=='0')
            {
                return 0;
            }
            int ans=recursion(str,i+1)*((str[i]=='*')?9:1);
            if(i+1<str.size())
            {
                if(str[i]!='*')
                {
                    if(str[i+1]!='*')
                    {
                        if((str[i]-'0')*10+(str[i+1]-'0')<=26)
                        {
                            ans+=recursion(str,i+2);
                        }
                    }
                    else
                    {
                        if(str[i]-'0'==1)
                        {
                            ans+=recursion(str,i+2)*9;
                        }
                        if(str[i]-'0'==2)
                        {
                            ans+=recursion(str,i+2)*6;
                        }
                    }
                }
                else
                {
                    if(str[i+1]!='*')
                    {
                        if(str[i+1]-'0'<=6)
                        {
                            ans+=recursion(str,i+2)*2;
                        }
                        else
                        {
                            ans+=recursion(str,i+2);
                        }
                    }
                    else
                    {
                        ans+=15*recursion(str,i+2);
                    }
                }
            }
            return ans;
        }
        int recursion_dp(string str,int i)
        {
            if(i==str.size())
            {
                return 1;
            }
            if(str[i]=='0')
            {
                return 0;
            }
            if(recursionDP[i]!=INT_MAX)
            {
                return dp[i];
            }
            long long ans=recursion_dp(str,i+1)*((str[i]=='*')?9:1);
            if(i+1<str.size())
            {
                if(str[i]!='*')
                {
                    if(str[i+1]!='*')
                    {
                        if((str[i]-'0')*10+(str[i+1]-'0')<=26)
                        {
                            ans+=recursion_dp(str,i+2);
                        }
                    }
                    else
                    {
                        if(str[i]-'0'==1)
                        {
                            ans+=recursion_dp(str,i+2)*9;
                        }
                        if(str[i]-'0'==2)
                        {
                            ans+=recursion_dp(str,i+2)*6;
                        }
                    }
                }
                else
                {
                    if(str[i+1]!='*')
                    {
                        if(str[i+1]-'0'<=6)
                        {
                            ans+=recursion_dp(str,i+2)*2;
                        }
                        else
                        {
                            ans+=recursion_dp(str,i+2);
                        }
                    }
                    else
                    {
                        ans+=15*recursion_dp(str,i+2);
                    }
                }
            }
            ans%=mod;
            dp[i]=ans;
            return ans;
        }
        int DP(string str)
        {
            dp[str.size()]=1;
            for(int i=str.size()-1;i>=0;i--)
            {
                if(str[i]!='0')
                {
                    dp[i]=dp[i+1]*((str[i]=='*')?9:1);
                    if(i+1<str.size())
                    {
                        if(str[i]!='*')
                        {
                            if(str[i+1]!='*')
                            {
                                if((str[i]-'0')*10+(str[i+1]-'0')<=26)
                                {   
                                    dp[i]+=dp[i+2];
                                }
                            }
                            else
                            {
                                if(str[i]-'0'==1)
                                {
                                    dp[i]+=dp[i+2]*9;
                                }
                                if(str[i]-'0'==2)
                                {
                                    dp[i]+=dp[i+2]*6;
                                }
                            }
                        }
                        else
                        {
                            if(str[i+1]!='*')
                            {
                                if(str[i+1]-'0'<=6)
                                {
                                    dp[i]+=dp[i+2]*2;
                                }
                                else
                                {
                                    dp[i]+=dp[i+2];
                                }
                            }
                            else
                            {
                                dp[i]+=dp[i+2]*15;
                            }
                        }
                    }
                }
                dp[i]=dp[i]%mod;
            }
            return (int)dp[0];
        }
};