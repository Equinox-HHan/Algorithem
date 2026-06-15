#include<bits/stdc++.h>
using namespace std;
//普通二叉树发返回最早公共祖先节点
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
        TreeNode* find(TreeNode *cur,TreeNode *p,TreeNode *q)
        {
            if(cur==nullptr||cur==p||cur==q)
            {
                return cur;
            }
            TreeNode *left=find(cur->left,p,q);
            TreeNode *right=find(cur->right,p,q);
            if(left==nullptr&&right==nullptr)
            {
                return nullptr;
            }
            if(left!=nullptr&&right!=nullptr)
            {
                return cur;
            }
            return left=nullptr?right:left;
        }
};