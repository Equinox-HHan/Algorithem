#include<bits/stdc++.h>
using namespace std;
//验证是否是平衡二叉树
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
    public:
        bool flag;
        bool isBalance(TreeNode *Head)
        {
            flag=true;
            height(Head);
            return flag;
        }
    private:
        int height(TreeNode *cur)
        {
            if(cur==nullptr||flag==false)
            {
                return 0;
            }
            int leftheight=height(cur->left);
            int rightheight=height(cur->right);
            if(abs(leftheight-rightheight)>1)
            {
                flag=false;
            }
            return max(leftheight,rightheight)+1;
        }   
};