#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int solve1(string str)
        {
            return recursion(str,0);
        }
        int recursion(string str,int i)
        {
            if(i==str.size())
            {
                return 1;
            }
            int ans;
            if(str[i]=='0')
            {
                ans=0;
            }
            else
            {
                ans=recursion(str,i+1);
                if(i+1<str.size()&&((str[i]-'0')*10+str[i+1]-'0')<=26)
                {
                    ans+=recursion(str,i+2);
                }
            }
            return ans;
        }
        int solve2(string str)
        {
            return recursion_dp(str,0);
        }
        int recursion_dp(string str,int i)
        {
            vector<int> dp(str.size(),INT_MAX);
            if(i==str.size())
            {
                return 1;
            }
            if(dp[i]!=INT_MAX)
            {
                return dp[i];
            }
            int ans;
            if(str[i]=='0')
            {
                ans=0;
            }
            else
            {
                ans=recursion_dp(str,i+1);
                if(i+1<str.size()&&((str[i]-'0')*10+str[i+1]-'0')<=26)
                {
                    ans+=recursion(str,i+2);
                }
                dp[i]=ans;
            }
            return ans;
        }
        int solve3(string str)
        {
            return DP(str);
        }
        int DP(string str)
        {
            vector<int> dp(str.size(),INT_MAX);
            dp[str.size()]=1;
            for(int i=str.size()-1;i>=0;i--)
            {
                if(str[i]=='0')
                {
                    dp[i]=0;
                }
                else
                {
                    dp[i]=dp[i+1];
                    if(i+1<str.size()&&((str[i]-'0')*10+str[i+1]-'0')<=26)
                    {
                        dp[i]+=dp[i+2];
                    }
                }
            }
            return dp[0];
        }
        int solve4(string str)
        {
            return DP2(str);
        }
        int DP2(string str)
        {
            int next=1;
            int nextNext=0;
            for(int i=str.size()-1,cur;i>=0;i--)
            {
                if(str[i]=='0')
                {
                    cur=0;
                }
                else
                {
                    cur=next;
                    if(i+1<str.size()&&((str[i]-'0')*10+str[i+1]-'0')<=26)
                    {
                        cur+=nextNext;
                    }
                }
                nextNext=next;
                next=cur;
            }
            return next;
        }
};