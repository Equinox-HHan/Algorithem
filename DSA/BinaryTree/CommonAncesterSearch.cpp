#include<bits/stdc++.h>
using namespace std;
//找到BST中两个节点的最近公共祖先
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
class solution
{
    public:
        TreeNode *left=nullptr;
        TreeNode *right=nullptr;
        TreeNode *finfFunction(TreeNode *cur,TreeNode *&left,TreeNode *&right)//or默认左值小于右值
        {
            while(cur->value!=left->value&&cur->value!=right->value)
            {
                if(cur->value>min(right->value,left->value)&&cur->value<max(left->value,right->value))
                {
                    break;
                }
                cur=(cur->value<min(left->value,right->value))?cur->right:cur->left;
            }
            return cur;
        }
};