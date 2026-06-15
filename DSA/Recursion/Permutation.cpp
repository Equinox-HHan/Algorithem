#include<bits/stdc++.h>
using namespace std;
//没有重复项数字的全排列
class Solution
{
    public:
        vector<vector<int>> permute(vector<int> &OriginalArray)
        {
            vector<vector<int>> ans;
            Function(OriginalArray,0,ans);
            return ans;
        }  
    private:
        void Function(vector<int> &OriginalArray,int index,vector<vector<int>> &ans)
        //这里的OriginalArray是一个全局变量
        {
            if(index==OriginalArray.size())
            {
                vector<int> temp(OriginalArray);
                ans.push_back(temp);
            }
            else
            {
                for(int i=index;i<OriginalArray.size();i++)
                {
                    swap(OriginalArray[index],OriginalArray[i]);
                    Function(OriginalArray,index+1,ans);
                    swap(OriginalArray[index],OriginalArray[i]);
                }
            }
        }
};
//有重复项数字的全排列
class Solution2
{
    public:
        vector<vector<int>> permuteUnique(vector<int> &OriginalArray)
        {
            vector<vector<int>> ans;
            sort(OriginalArray.begin(),OriginalArray.end());
            Function(OriginalArray,0,ans);
            return ans;
        }
    private:
        void Function(vector<int> &OriginalArray,int index,vector<vector<int>> &ans)
        {
            if(index==OriginalArray.size())
            {
                vector<int> temp(OriginalArray);
                ans.push_back(temp);
            }
            else
            {
                for(int i=index;i<OriginalArray.size();i++)
                {
                    if(i!=index && OriginalArray[i]==OriginalArray[index])
                    {
                        continue;
                    }
                    swap(OriginalArray[index],OriginalArray[i]);
                    Function(OriginalArray,index+1,ans);
                    swap(OriginalArray[index],OriginalArray[i]);
                }
            }
        }
};
int main()
{
    vector<int> OriginalArray={1,2,3};
    Solution S;
    vector<vector<int>> ans=S.permute(OriginalArray);
    for(const auto &element:ans)
    {
        for(const auto &num:element)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    Solution2 S2;
    vector<int> OriginalArray2={1,1,2};
    vector<vector<int>> ans2=S2.permuteUnique(OriginalArray2);
    for(const auto &element:ans2)
    {
        for(const auto &num:element)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}