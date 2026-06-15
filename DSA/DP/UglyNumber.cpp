#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int solve()
        {
            cin>>number;
            return func(number);
        }
    private:
        int number;
        int func(int number)
        {
            int dp[10000];
            dp[1]=1;
            int ptr2=1,ptr3=1,ptr5=1;
            for(int i=2;i<=number;i++)
            {
                int a=dp[ptr2]*2;
                int b=dp[ptr3]*3;
                int c=dp[ptr5]*5;
                int cur=min({a,b,c});
                dp[i]=cur;
                if(cur==a)
                {
                    ptr2++;
                }
                if(cur==b)
                {
                    ptr3++;
                }
                if(cur==c)
                {
                    ptr5++;
                }
            }
            return dp[number];
        }
};
int main()
{
    return 0;
}