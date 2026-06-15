#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void solve()
        {
            cin>>str;
            for(int i=0;i<10;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(func(0,i,j))
                    {
                        cout<<"True;"<<endl;
                    }
                    else
                    {
                        cout<<"False;"<<endl;
                    }
                }
            }
        }
    private:
        string str;
        char arr[10][10];
        bool func(int k,int i,int j)
        {
            if(k==str.size())
            {
                return true;
            }
            if(i<0&&i==str.size()&&j<0&&j==str.size()&&str[k]!=arr[i][j])
            {
                return false;
            }
            char temp=arr[i][j];
            arr[i][j]=0;
            bool ans=func(k+1,i-1,j-1)||func(k+1,i,j+1)||func(k+1,i+1,j)||func(k+1,i+1,j+1);
            arr[i][j]=temp;
            return ans;
        }       
};