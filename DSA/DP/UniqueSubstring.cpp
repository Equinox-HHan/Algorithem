#include<bits/stdc++.h>
using namespace std;
//子串问题是必须相连的
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
        int dp[26];
        int ans=0;
        int func(string str)
        {
            memset(dp,0,sizeof(dp));
            dp[str[0]-'a']=1;
            int leng=1;
            for(int i=1;i<str.size();i++)
            {
                int cur=str[i]-'a';
                int pre=str[i-1]-'a';
                if((pre==25&&cur==0)||(pre+1==cur))
                {
                    leng+=1;
                }
                else
                {
                    leng=1;
                }
                dp[cur]=max(dp[cur],leng);
            }
            for(int i=0;i<=25;i++)
            {
                ans+=dp[i];
            }
            return ans;
        }
};
int main()
{
    return 0;
}