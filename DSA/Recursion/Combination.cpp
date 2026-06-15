#include<bits/stdc++.h>
using namespace std;
//生成字符串的全部组合
//组合只关心元素是否被选中（相同元素选中几个），不关心元素的顺序
class Solution
{
    public:
        vector<vector<int>> combine(vector<int> &OriginalArray)
        {
            vector<vector<int>> ans;
            vector<int> path(OriginalArray.size());
            sort(OriginalArray.begin(),OriginalArray.end());
            Function(OriginalArray,path,0,0,ans);
            return ans;
        }
        void printResult(const vector<vector<int>> &ans)
        {
            for(const auto &element:ans)
            {
                for(const auto &num:element)
                {
                    cout<<num<<" ";
                }
                cout<<endl;
            }
        }
    private:
        void Function(const vector<int> &Orighinal,vector<int> &path,int index,int size,vector<vector<int>> &ans)
        {
            if(index==Orighinal.size())
            {
                vector<int> temp(path.begin(),path.begin()+size);
                ans.push_back(temp);
            }
            else
            {
                int j=index+1;
                while(j<Orighinal.size()&&Orighinal[j]==Orighinal[index])
                {
                    j++;
                }
                Function(Orighinal,path,j,size,ans);
                int currentSize=size;
                for(int k=index;k<j;k++)
                {
                    path[currentSize]=Orighinal[k];
                    currentSize++;
                    Function(Orighinal,path,j,currentSize,ans);
                }
            }
        }

};
int main()
{
    vector<int> OriginalArray={1,2,2};
    Solution S;
    vector<vector<int>> ans=S.combine(OriginalArray);
    S.printResult(ans);
    return 0;
}