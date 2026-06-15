#include<bits/stdc++.h>
#include"LongestSubstring.h"
using namespace std;
//最长回文数的子序列问题
class Solve1
{
    public:
        int solve1()
        {
            cin>>str1;
            return reverseString(str1);
        }
    private:
        string str1;
        Solution sol;
        int reverseString(string str)
        {
            auto rev=[](string str)
            {
                reverse(str.begin(),str.end());
                return str;
            };
            return sol.DP(str,rev(str));
        }
};
class Solve2
{
    public:
        int solve2()
        {
            auto func=[](int dp[][20])
            {
                for(int i=0;i<20;i++)
                {
                    for(int j=0;j<20;j++)
                    {
                        dp[i][j]=-1;
                    }
                }
            };
        }
    private:
        string str2;
        //假设这里的str2长度是20;
        int dp[20][20];
        int recursion(const string &str,int left,int right)
        {
            if(left==right)
            {
                return 1;
            }
            if(left+1==right)
            {
                return (str[left]==str[right])?2:1;
            }
            else
            {
                if(str[left]==str[right])
                {
                    return 2+recursion(str,left+1,right-1);
                }
                else
                {
                    return max(recursion(str,left+1,right),recursion(str,left,right-1));
                }
            }
        }
        int recursion_dp(const string &str,int left,int right)
        {
            if(dp[left][right]!=-1)
            {
                return dp[left][right];
            }
            int ans;
            if(left==right)
            {
                ans=1;
            }
            if(left=1==right)
            {
                ans=(str[left]==str[right])?2:1;
            }
            else
            {
                if(str[left]==str[right])
                {
                    ans=dp[left+1][right-1]+2;
                }
                else
                {
                    ans=max(dp[left+1][right],dp[left][right-1]);
                }
            }
            dp[left][right]=ans;
            return ans;
        }
        int DP(const string &str)
        {
            for(int k=19;k>=0;k--)
            {
                dp[k][k]=1;//即为left==right的情况
                if(k+1<20)
                {
                    dp[k][k+1]=(str[k]==str[k+1])?2:1;
                }
                for(int right=k+2;right<20;right++)
                {
                    if(str[k]==str[right])
                    {
                        dp[k][right]=2+dp[k+1][right-1];
                    }
                    else
                    {
                        dp[k][right]=max(dp[k][right-1],dp[k+1][right]);
                    }
                }
            }
            return dp[0][19];
        }
        int dp_zip(const string &str)
        {
            int dp[20];
            memset(dp,0,sizeof(dp));
            for(int i=19;i>=0;i--)
            {
                dp[i]=1;
                int leftdown=0,backup;
                if(i+1<20)
                {
                    leftdown=dp[i+1];
                    dp[i+1]=(str[i]==str[i+1])?2:1;
                }
                    for(int j=i+2;j<20;j++)
                    {
                        backup=dp[j];
                        if(str[i]==str[j])
                        {
                            dp[j]=leftdown+2;
                        }
                        else
                        {
                            dp[j]=max(dp[j],dp[j-1]);
                        }
                        leftdown=backup;
                    }
            }
            return dp[19];
        }
};