#include<bits/stdc++.h>
using namespace std;
//经典问题：最长公共子序列问题
class Solution
{
    public:
        string str1,str2;
        //假设str的长度统一为10;
        int dp[11][11];
        int dp_zip[11];
        int recursion(const string &str1,const string &str2,int x,int y)
        {
            if(x==0&&y==0)
            {
                return (str1[0]==str2[0])?1:0;
            }
            int ans;
            if(str1[x]==str2[y])
            {
                ans=1+recursion(str1,str2,x-1,y-1);
            }
            else
            {
                ans=min(recursion(str1,str2,x,y-1),recursion(str1,str2,x-1,y));
            }
            return ans;
        }
        int recursion_dp(const string &str1,const string &str2,int len1,int len2)
        {
            if(dp[len1][len2]!=-1)
            {
                return dp[len1][len2];                
            }          
            int ans;
            if(len1==0&&len2==0)
            {
                ans=0;
            }
            if(str1[len1-1]==str2[len2-1])
            {
                ans=1+recursion(str1,str2,len1-1,len2-1);
            }
            else
            {
                ans=min(recursion(str1,str2,len1,len2-1),recursion(str1,str2,len1-1,len2));
            }
            dp[len1][len2]=ans;
            return ans;
        }
        int DP(const string &str1,const string &str2)
        {
            dp[0][0]=0;
            for(int i=1;i<11;i++)
            {
                dp[0][i]=0;
            }
            for(int j=1;j<11;j++)
            {
                dp[j][0]=0;
            }
            //dp表初始化
            for(int i=1;i<11;i++)
            {
                for(int j=1;j<11;j++)
                {
                    if(str1[i-1]==str2[j-1])
                    {
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
                    }
                }
            }
            return dp[10][10];
        }
        int DP_zip(const string &str1,const string &str2)
        {
            int dp[11];
            //这里有一处优化:字符串长度短的充当列数
            //这里假设str1长度小于str2长度
            memset(dp,0,sizeof(dp));
            for(int row=1;row<=str2.size();row++)
            {
                int leftup=0,backup;
                for(int cline=1;cline<=str1.size();cline++)
                {
                    backup=dp[cline];
                    if(str1[cline-1]==str2[row-1])
                    {
                        dp[cline]=1+leftup;
                    }
                    else
                    {
                        dp[cline]=max(dp[cline-1],dp[cline]);
                    }
                    leftup=backup;
                }
            }
            return dp[10];
        }
};