#include<bits/stdc++.h>
using namespace std;
//计算二叉树最大宽度，其中包括NULL
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
        static const int MAXN=100;
        TreeNode* NodeQueue[MAXN];
        int IDQueue[MAXN];
    public:
        int Function(TreeNode *Head)
        {
            if(Head=nullptr)
            {
                return 0;
            }
            int ans=0;
            int Left=0,Right=0;
            NodeQueue[Right]=Head;
            IDQueue[Right++]=1;
            while(Left<Right)
            {
                int size=Right-Left;
                ans=max(ans,static_cast<int>(IDQueue[Right-1]-IDQueue[Left])+1);
                for(int i=0;i<size;i++)
                {
                    TreeNode *current=NodeQueue[Left];
                    unsigned long long ID=IDQueue[Left++];
                    if(current->left!=nullptr)
                    {
                        NodeQueue[Right]=current->left;
                        IDQueue[Right++]=ID*2;
                    }
                    if(current->right!=nullptr)
                    {
                        NodeQueue[Right]=current->right;
                        IDQueue[Right]=ID*2+1;
                    }
                }
            }
            return ans;
        }
};
#include<bits/stdc++.h>
using namespace std;

// ... (your existing TreeNode and Solution class code here) ...

int main() {
    // Test Case 1: Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    //      / \
    //     7   8
    // Maximum width including null nodes: The widest level is level 3 (nodes 4,5,6 with nulls between)
    // Expected width: 3 (positions 4,5,6) or more if counting nulls properly
    
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(5, node7, node8);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3, nullptr, node6);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* root1 = new TreeNode(1, node2, node3);
    
    Solution solution;
    int result = solution.Function(root1);
    
    cout << "Test Case 1 (General binary tree):" << endl;
    cout << "Tree structure:" << endl;
    cout << "       1" << endl;
    cout << "      / \\" << endl;
    cout << "     2   3" << endl;
    cout << "    / \\   \\" << endl;
    cout << "   4   5   6" << endl;
    cout << "      / \\" << endl;
    cout << "     7   8" << endl;
    cout << "Expected maximum width (including nulls): 3" << endl;
    cout << "Actual maximum width: " << result << endl << endl;
    
    // Test Case 2: Perfect binary tree
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    // Maximum width: 4 (all nodes at level 3)
    
    TreeNode* node7_perfect = new TreeNode(7);
    TreeNode* node6_perfect = new TreeNode(6);
    TreeNode* node5_perfect = new TreeNode(5);
    TreeNode* node4_perfect = new TreeNode(4);
    TreeNode* node3_perfect = new TreeNode(3, node6_perfect, node7_perfect);
    TreeNode* node2_perfect = new TreeNode(2, node4_perfect, node5_perfect);
    TreeNode* root_perfect = new TreeNode(1, node2_perfect, node3_perfect);
    
    result = solution.Function(root_perfect);
    cout << "Test Case 2 (Perfect binary tree):" << endl;
    cout << "          1" << endl;
    cout << "        /   \\" << endl;
    cout << "       2     3" << endl;
    cout << "      / \\   / \\" << endl;
    cout << "     4   5 6   7" << endl;
    cout << "Expected maximum width: 4" << endl;
    cout << "Actual maximum width: " << result << endl << endl;
    
    // Test Case 3: Single node tree
    TreeNode* singleNode = new TreeNode(10);
    result = solution.Function(singleNode);
    cout << "Test Case 3 (Single node):" << endl;
    cout << "Tree: [10]" << endl;
    cout << "Expected maximum width: 1" << endl;
    cout << "Actual maximum width: " << result << endl << endl;
    
    // Test Case 4: Empty tree
    TreeNode* emptyTree = nullptr;
    result = solution.Function(emptyTree);
    cout << "Test Case 4 (Empty tree):" << endl;
    cout << "Tree: null" << endl;
    cout << "Expected maximum width: 0" << endl;
    cout << "Actual maximum width: " << result << endl << endl;
    
    // Test Case 5: Left-skewed tree
    //       7
    //      /
    //     8
    //    /
    //   9
    //  /
    // 10
    // Maximum width: 1 (each level has only one node)
    
    TreeNode* node10_left = new TreeNode(10);
    TreeNode* node9_left = new TreeNode(9, node10_left, nullptr);
    TreeNode* node8_left = new TreeNode(8, node9_left, nullptr);
    TreeNode* root_left = new TreeNode(7, node8_left, nullptr);
    
    result = solution.Function(root_left);
    cout << "Test Case 5 (Left-skewed tree):" << endl;
    cout << "       7" << endl;
    cout << "      /" << endl;
    cout << "     8" << endl;
    cout << "    /" << endl;
    cout << "   9" << endl;
    cout << "  /" << endl;
    cout << " 10" << endl;
    cout << "Expected maximum width: 1" << endl;
    cout << "Actual maximum width: " << result << endl << endl;
    
    // Test Case 6: Tree with missing nodes that create wide gaps
    //          1
    //        /   \
    //       2     3
    //      /       \
    //     4         5
    //    /           \
    //   6             7
    // Maximum width including nulls: The last level has nodes at positions far apart
    
    TreeNode* node7_wide = new TreeNode(7);
    TreeNode* node6_wide = new TreeNode(6);
    TreeNode* node5_wide = new TreeNode(5, nullptr, node7_wide);
    TreeNode* node4_wide = new TreeNode(4, node6_wide, nullptr);
    TreeNode* node3_wide = new TreeNode(3, nullptr, node5_wide);
    TreeNode* node2_wide = new TreeNode(2, node4_wide, nullptr);
    TreeNode* root_wide = new TreeNode(1, node2_wide, node3_wide);
    
    result = solution.Function(root_wide);
    cout << "Test Case 6 (Tree with wide gaps):" << endl;
    cout << "          1" << endl;
    cout << "        /   \\" << endl;
    cout << "       2     3" << endl;
    cout << "      /       \\" << endl;
    cout << "     4         5" << endl;
    cout << "    /           \\" << endl;
    cout << "   6             7" << endl;
    cout << "Expected maximum width (including nulls): 4" << endl;
    cout << "Actual maximum width: " << result << endl << endl;
    
    // Test Case 7: Tree where middle level has maximum width
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5
    //  / \     / \
    // 6   7   8   9
    
    TreeNode* node9_mid = new TreeNode(9);
    TreeNode* node8_mid = new TreeNode(8);
    TreeNode* node7_mid = new TreeNode(7);
    TreeNode* node6_mid = new TreeNode(6);
    TreeNode* node5_mid = new TreeNode(5, node8_mid, node9_mid);
    TreeNode* node4_mid = new TreeNode(4, node6_mid, node7_mid);
    TreeNode* node3_mid = new TreeNode(3, nullptr, node5_mid);
    TreeNode* node2_mid = new TreeNode(2, node4_mid, nullptr);
    TreeNode* root_mid = new TreeNode(1, node2_mid, node3_mid);
    
    result = solution.Function(root_mid);
    cout << "Test Case 7 (Maximum width at middle level):" << endl;
    cout << "       1" << endl;
    cout << "      / \\" << endl;
    cout << "     2   3" << endl;
    cout << "    /     \\" << endl;
    cout << "   4       5" << endl;
    cout << "  / \\     / \\" << endl;
    cout << " 6   7   8   9" << endl;
    cout << "Expected maximum width: 4" << endl;
    cout << "Actual maximum width: " << result << endl << endl;
    
    // Test Case 8: Tree with very wide last level
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5
    //  /         \
    // 6           7
    
    TreeNode* node7_last = new TreeNode(7);
    TreeNode* node6_last = new TreeNode(6);
    TreeNode* node5_last = new TreeNode(5, nullptr, node7_last);
    TreeNode* node4_last = new TreeNode(4, node6_last, nullptr);
    TreeNode* node3_last = new TreeNode(3, nullptr, node5_last);
    TreeNode* node2_last = new TreeNode(2, node4_last, nullptr);
    TreeNode* root_last = new TreeNode(1, node2_last, node3_last);
    
    result = solution.Function(root_last);
    cout << "Test Case 8 (Wide last level):" << endl;
    cout << "       1" << endl;
    cout << "      / \\" << endl;
    cout << "     2   3" << endl;
    cout << "    /     \\" << endl;
    cout << "   4       5" << endl;
    cout << "  /         \\" << endl;
    cout << " 6           7" << endl;
    cout << "Expected maximum width: 4" << endl;
    cout << "Actual maximum width: " << result << endl;
    
    // Note: There's a bug in your Function implementation
    // In the if condition checking for null Head, you have:
    // if(Head=nullptr)  // This is assignment, not comparison!
    // It should be:
    // if(Head == nullptr)
    
    // Also, in the right child assignment, you missed the increment:
    // IDQueue[Right]=ID*2+1;  // Missing Right++
    // It should be:
    // IDQueue[Right++]=ID*2+1;
    
    return 0;
}