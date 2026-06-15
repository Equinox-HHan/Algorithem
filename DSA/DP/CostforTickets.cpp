#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        const vector<int> duration={1,3,7};
        int solve1(const vector<int> &days,const vector<int> &cost)
        {
            return recursion1(days,cost,0);
        }
        int recursion1(const vector<int> &days,const vector<int> &cost,int i)
        {
            if(i==days.size())
            {
                return 0;
            }
            int ans=INT_MAX;
            for(int k=0;k<3;k++)
            {
                int j=i;
                while(j<days.size()&&days[i]+duration[k]>days[j])
                {
                    j++;
                }
                ans=min(ans,cost[k]+recursion1(days,cost,j));
            }
            return ans;
        }
        int solve2(const vector<int> &days,const vector<int> &cost)
        {
            int n=days.size();
            vector<int> dp(n,INT_MAX);
            return recursion_dp(dp,days,cost,0);
        }
        int recursion_dp(vector<int> &dp,const vector<int> &days,const vector<int> &cost,int i)
        {
            if(i==days.size())
            {
                return 0;
            }
            if(dp[i]!=INT_MAX)
            {
                return dp[i];
            }
            int ans=INT_MAX;
            for(int k=0;k<3;k++)
            {
                int j=i;
                while(j<days.size()&&days[i]+duration[k]>days[j])
                {
                    j++;
                }
                ans=min(ans,cost[k]+recursion_dp(dp,days,cost,j));
            }
            dp[i]=ans;
            return ans;
        }
        
        int DP(const vector<int> &days,const vector<int> &cost,int i)
        {
            int n=days.size();
            vector<int> dp(n+1,INT_MAX);
            dp[n]=0;
            for(int i=n-1;i>=0;i--)
            {
                for(int k=0;k<3;k++)
                {
                    int j=i;
                    while(j<days.size()&&days[i]+duration[k]>days[j])
                    {
                        j++;
                    }
                    dp[i]=min(dp[i],cost[k]+dp[j]);
                }
            }
            return dp[0];
        }
};