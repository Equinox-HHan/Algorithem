#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value=0;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int number)
    {
        value=number;
        left=nullptr;
        right=nullptr;
    }
    TreeNode(int number,TreeNode *left,TreeNode *right)
    {
        value=number;
        this->left=left;
        this->right=right;
    }
};
class Solution
{
    private:
        int mostLeaf(TreeNode *cur,int level)
        {
            while(cur!=nullptr)
            {
                level+=1;
                cur=cur->left;
            }
            return level-1;
        }
        int Recursion(TreeNode *cur,int level,int height)
        {
            if(level=height)
            {
                return 1;
            }
            if(mostLeaf(cur->right,level+1)==height)
            {
                return ((1<<(level-height))+Recursion(cur->right,level+1,height));
            }
            else
            {
                return ((1<<(level-height-1))+Recursion(cur->left,level+1,height));
            }
        }
    public:
        int countFunction(TreeNode *Head)
        {
            if(Head==nullptr)
            {
                return 0;
            }
            int height=mostLeaf(Head,1);
            return Recursion(Head,1,height);
        }
};