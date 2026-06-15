#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        string countAtoms(const string &str)
        {
            int pos=0;
            string ans="";
            map<string,int> countMap;
            countMap=func(str,pos);            
            for(const auto &pair:countMap)
            {
                ans+=pair.first;
                if(pair.second>1)
                {
                    ans+=to_string(pair.second);
                }
            }
            return ans;
        }
    private:
        map<string,int> func(const string &str,int &pos)
        {
            map<string,int> ans,pre;
            int count=0;string name;
            while(pos<str.length()&&str[pos]!=')')
            {
                if(str[pos]>'0'&&str[pos]<='9')
                {
                    count=count*10+str[pos];
                    pos+=1;
                }
                else if(!isupper(str[pos]))
                {
                    name+=str[pos];
                    pos+=1;
                }
                else if(isupper(str[pos])||str[pos]=='(')
                {
                    fill(ans,pre,count,name);
                    pre.clear();
                    name.clear();
                    count=0;
                    if(isupper(str[pos]))
                    {
                        name+=str[pos];
                    }
                    else
                    {
                        pos+=1;
                        pre=func(str,pos);
                    }
                }
            }
            fill(ans,pre,count,name);
            if(pos<str.length()&&str[pos]==')')
            {
                pos+=1;
            }
            return ans;
        }
        void fill(map<string,int> &ans,map<string,int> &pre,int count,string &name)
        {
            if(!name.empty()||!pre.empty())
            {
                count=(count==0)?1:count;
                if(!name.empty())
                {
                    ans[name]+=count;
                }
                else
                {
                    for(const auto &pair:pre)
                    {
                        ans[pair.first]+=pair.second*count;
                    }
                }
            }
        }
};