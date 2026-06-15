#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int solve()
        {
            for(int i=0;i<10;i++)
            {
                for(int j=0;j<10;j++)
                {
                    cin>>arr[i][j];
                }
            }
            //假设原数组的size是10×10;
            recursion(10,10);
            auto func=[](int dp[10][10])->void
            {
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        dp[i][j]=-1;
                    }
                }
            };
            recursion_dp(10,10);
            DP(10,10);
            DP_zip(10,10);
        }
    private:
        int arr[10][10];
        int dp[10][10];
        int recursion(int x,int y)
        {
            if(x==0&&y==0)
            {
                return arr[x][y];
            }
            int up=INT_MAX;
            int left=INT_MAX;
            if(x-1>=0)
            {
                up=recursion(x-1,y);
            }
            if(y-1>=0)
            {
                left=recursion(x,y-1);
            }
            return arr[x][y]+min(up,left);
        }
        int recursion_dp(int x,int y)
        {
            if(dp[x][y]!=-1)
            {
                return dp[x][y];
            }
            int ans;
            if(x==0&&y==0)
            {
                ans=arr[x][y];
            }
            int up=INT_MAX;
            int left=INT_MAX;
            if(x-1>=0)
            {
                up=recursion_dp(x-1,y);
            }
            if(y-1>=0)
            {
                left=recursion_dp(x,y-1);
            }
            ans=arr[x][y]+min(up,left);
            dp[x][y]=ans;
            return ans;
        }
        int DP(int x,int y)
        {
            dp[0][0]=arr[0][0];
            for(int i=1;i<x;i++)
            {
                dp[i][0]=dp[i-1][0]+arr[i][0];
            }
            for(int j=1;j<y;j++)
            {
                dp[0][j]=dp[0][j-1]+arr[0][j];
            }
            for(int i=1;i<x;i++)
            {
                for(int j=1;j<y;j++)
                {
                    int left=dp[i][j-1]+arr[i][j];
                    int up=dp[i-1][j]+arr[i][j];
                    dp[i][j]=min(left,up);
                }
            }
            return dp[x][y];
        }
        int DP_zip(int x,int y)
        //dp表一维空间压缩
        {
            int dp[10];
            dp[0]=arr[0][0];
            for(int i=1;i<y;i++)
            {
                dp[i]=dp[i-1]+arr[0][i];
            }
            for(int k=1;k<x;k++)
            {
                dp[0]=dp[0]+arr[k][0];
                for(int j=1;j<y;j++)
                {
                    dp[j]=min(dp[j-1]+arr[k][j],dp[j]+arr[k][j]);
                }
            }
            return dp[y];
        }
};
