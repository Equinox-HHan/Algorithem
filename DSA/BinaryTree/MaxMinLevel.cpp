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
    public:
        int FindMax(TreeNode *Head)
        {
            return(Head==nullptr?0:max(FindMax(Head->left),FindMax(Head->right))+1); 
        }
        int FindMin(TreeNode *Head)
        {
            if(Head==nullptr)
            {
                return 0;
            }
            if(Head->left==nullptr&&Head->right==nullptr)
            {
                return 1;
            }
            int leftDeep=INT_MAX;
            int rightDeep=INT_MAX;
            if(Head->left!=nullptr)
            {
                leftDeep=FindMin(Head->left);
            }
            if(Head->right!=nullptr)
            {
                rightDeep=FindMin(Head->right);
            }
            return min(leftDeep,rightDeep)+1;
        }
};
