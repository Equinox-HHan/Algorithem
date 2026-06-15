#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        string decodeString(const string str)
        {
            int pos=0;
            return func(pos,str);
        }
    private:
        string func(int &pos,const string &str)
        {
            string path="";
            int count=0;
            while(pos<str.length()&&str[pos]!=']')
            {
                if(isalpha(str[pos]))
                {
                    path+=(str[pos]);
                }
                else if(str[pos]>='0'&&str[pos]<='9')
                {
                    count=count*10+str[pos];
                }
                else
                {
                    pos+=1;
                    string innerStr=func(pos,str);
                    for(count;count>0;count--)
                    {
                        path+=innerStr;
                    }
                }
            }
            if(pos<str.length()&&str[pos]==']')
            {
                pos+=1;
            }
            return path;
        }    
};  
