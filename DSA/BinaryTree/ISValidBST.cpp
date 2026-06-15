#include<bits/stdc++.h>
using namespace std;//验证是否是搜索二叉树
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
class Solution1
{
    public:
        bool isValidBST(TreeNode* root) 
        {
            if(root==nullptr)
            {
                return true;
            }
            stack<TreeNode*> Stack;
            TreeNode *pre=nullptr;
            TreeNode *head=root;
            while(!Stack.empty()||head!=nullptr)
            {
                if(head!=nullptr)
                {
                    Stack.push(head);
                    head=head->left;
                }
                else
                {
                    head=Stack.top();
                    Stack.pop();
                    if(head->value<=pre->value&&pre!=nullptr)
                    {
                        return false;
                    }
                    pre=head;
                    head=head->right;
                }
            }
            return true;
        }
};
class Solution2 {
public:
    struct Info {
        bool isBST;
        long long minVal; // 使用 long long 防止 int 边界溢出
        long long maxVal;
    };

    Info process(TreeNode* x) {
        if (x == nullptr) {
            // 空树是 BST，为了不影响父节点的 min/max 判断，返回反向极限值
            return {true, LLONG_MAX, LLONG_MIN};
        }

        Info leftInfo = process(x->left);
        Info rightInfo = process(x->right);

        // 计算当前整棵树的最大值和最小值
        long long curMin = min({(long long)x->value, leftInfo.minVal, rightInfo.minVal});
        long long curMax = max({(long long)x->value, leftInfo.maxVal, rightInfo.maxVal});

        // 判断是否满足 BST 条件：
        // 1. 左右子树本身是 BST
        // 2. 左子树最大值 < 当前值
        // 3. 右子树最小值 > 当前值
        bool isBST = leftInfo.isBST && rightInfo.isBST &&leftInfo.maxVal<x->value&&x->value<rightInfo.minVal;

        return {isBST, curMin, curMax};
    }

    bool isValidBST(TreeNode* root) {
        return process(root).isBST;
    }
};