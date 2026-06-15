#include<bits/stdc++.h>
using namespace std;
//字符串的全部子序列（去重）
class Solution
{
    public:
        vector<string> generateF1(const string &str)
        {
            unordered_set<string> Set;
            string path="";
            function1(str,0,path,Set);
            vector<string> result;
            for(const auto &element:Set)
            {
                result.push_back(element);
            }
            return result;
        }
    private:
        void function1(const string &str,int index,string &path,unordered_set<string> &Set)
        {
            if(index==str.length())
            {
                Set.insert(path);
                return;
            }
            path.push_back(str[index]);
            function1(str,index+1,path,Set);
            path.pop_back();
            function1(str,index+1,path,Set);
        }
    public:
        vector<string> generateF2(const string &str)
        {
            string path(str.length(),' ');
            unordered_set<string> Set;
            vector<string> result;
            function2(str,0,path,Set,0);
            for(const auto &element:Set)
            {
                result.push_back(element);
            }
            return result;
        }
    private:
        void function2(const string &str,int index,string &path,unordered_set<string> &Set,int size)
        {
            if(index==str.length())
            {
                Set.insert(path.substr(0,size));
                return;
            }
            path[size]=str[index];
            function2(str,index+1,path,Set,size+1);
            function2(str,index+1,path,Set,size);
        }
};
int main()
{
    string str="abc";
    Solution solution;
    vector<string> result1=solution.generateF1(str);
    for(const auto &element:result1)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    vector<string> result2=solution.generateF2(str);
    for(const auto &element:result2)
    {
        cout<<element<<" ";
    }
    cout<<endl;
    return 0;
}