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
        TreeNode *TrimBST(TreeNode *root,int minNumber,int maxNumber)
        {
            if(root==nullptr)
            {
                return nullptr;
            }          
            if(root->value<minNumber)
            {
                return TrimBST(root->right,minNumber,maxNumber);
            }
            if(root->value>maxNumber)
            {
                return TrimBST(root->left,minNumber,maxNumber);
            }
            root->left=TrimBST(root->left,minNumber,maxNumber);
            root->right=TrimBST(root->right,minNumber,maxNumber);
            return root;
        }
};
int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(0);
    root->right=new TreeNode(2);
    Solution solution;
    TreeNode *newRoot=solution.TrimBST(root,1,2);
    return 0;
}