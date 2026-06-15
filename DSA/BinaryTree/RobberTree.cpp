#include<bits/stdc++.h>
using namespace std;
//二叉树的打家劫舍问题
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
        static int yes,no;
        int Rob(TreeNode* root)
        {
            function(root);
            return max(yes,no);
        }
    private:
        void function(TreeNode *root)
        {
            if(root=nullptr)
            {
                yes=0;
                no=0;
            }
            else
            {
                int y=root->value;
                int n=0;
                function(root->left);
                y+=no;
                n+=max(yes,no);
                function(root->right);
                y+=no;
                n+=max(yes,no);
                yes=y;
                no=n;
            }
        }
};
int main()
{
    return 0;
}