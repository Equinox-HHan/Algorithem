#include<bits/stdc++.h>
using namespace std;
//最长有效括号串
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
        int func(string str)
        {
            int ans=0;
            int dp[100000];
            dp[0]=0;
            for(int i=1;i<=str.size();i++)
            {
                if(str[i]=='(')
                {
                    dp[i]=0;
                }
                else
                {
                    int p=i-dp[i-1]-1;
                    if(p>=0&&str[p]=='(')
                    {
                        dp[i]=dp[i-1]+2+((p-1>=0)?dp[p-1]:0);
                    }
                }
                ans=max(ans,dp[i]);
            }
            return ans;
        }
};
int main()
{
    return 0;
}