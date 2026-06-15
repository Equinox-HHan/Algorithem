#include<bits/stdc++.h>
using namespace std;
//根据先序和中序构建一个二叉树
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
        TreeNode* buildTree(vector<int> &preorder,vector<int> &inorder)
        {
            if(preorder.empty()||inorder.empty()||preorder.size()!=inorder.size())
            {
                return nullptr;
            }
            unordered_map<int,int> Hashmap;
            for(int i=0;i<inorder.size();i++)
            {
                Hashmap[inorder[i]]=i;
            }
            return function(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,Hashmap);
        }
    private:
        TreeNode* function(vector<int> &pre,int l1,int r1,vector<int> &in,int l2,int r2,unordered_map<int,int> &hashmap)
        {
            if(l1>r1)
            {
                return nullptr;
            }
            TreeNode *Head=new TreeNode(pre[l1]);
            if(l1==r1)
            {
                return Head;
            }
            int k=hashmap[pre[l1]];
            Head->left=function(pre,l1+1,l1+k-l2,in,l2,k-1,hashmap);
            Head->right=function(pre,l1+k-l2+1,r1,in,k+1,r2,hashmap);
            return Head;
        }
};
int main()
{
    return 0;
}