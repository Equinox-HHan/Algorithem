#include<bits/stdc++.h>
using namespace std;
//验证是否是完全二叉树
//c++ STL队列方法
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
class solution1
{
    public:
        bool isTree(TreeNode *Head)
        {
            if(Head==nullptr)
            {
                return true;
            }
            bool leaf=false;
            queue<TreeNode*> QUEUE;
            QUEUE.push(Head);
            while(!QUEUE.empty())
            {
                TreeNode* current=QUEUE.front();
                QUEUE.pop();
                if((current->left==nullptr&&current->right!=nullptr)||
                    leaf&&(current->left!=nullptr||current->right!=nullptr))
                    {
                        return false;
                    }
                if(current->left!=nullptr)
                {
                    QUEUE.push(current->left);
                }
                if(current->right!=nullptr)
                {
                    QUEUE.push(current->right);
                }
                if(current->left==nullptr||current->right==nullptr)
                {
                    leaf=true;
                }
            }
            return true;
        }
};
class solution2
{
    private:
        static const int MAXN=200;
        TreeNode* arr[MAXN];
        int left;
        int right;
    public:
        bool isTree(TreeNode *Head)
        {
            if(Head==nullptr)
            {
                return true;
            }
            left=0;right=0;
            bool leaf=false;
            arr[right++]=Head;
            while(left<right)
            {
                TreeNode* current=arr[left++];
                if((current->left==nullptr&&current->right!=nullptr)||
                    leaf&&(current->left!=nullptr||current->right!=nullptr))
                    {
                        return false;
                    }
                if(current->left!=nullptr)
                {
                    arr[right++]=current->left;
                }
                if(current->right!=nullptr)
                {
                    arr[right++]=current->left;
                }
                if(current->left==nullptr||current->right==nullptr)
                {
                    leaf=true;
                }
            }
            return true;
        }
};
