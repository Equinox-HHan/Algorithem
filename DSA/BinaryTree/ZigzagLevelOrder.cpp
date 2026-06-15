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
    TreeNode(int number,TreeNode* left,TreeNode *right)
    {
        value=number;
        this->left=left;
        this->right=right;
    }
};
class Solution
{
    private:
        static const int MAXN=20;
        TreeNode* arr[MAXN];
        int Left,Right;
    public:
        vector<vector<int>> Function(TreeNode *Head)
        {
            vector<vector<int>> ans;
            if(Head!=nullptr)
            {
                Left=Right=0;
                arr[Right++]=Head;
                bool reverse=false;
                while(Left<Right)
                {
                    vector<int> level;
                    int size=Right-Left;
                    int i=(reverse==false)?Left:Right-1;
                    int j=(reverse==false)?1:-1;
                    for(int k=0;k<size;i+=j,k++)
                    {
                        TreeNode *current=arr[i];
                        level.push_back(current->value);
                    }
                    for(int count=0;count<size;count++)
                    {
                        TreeNode *current=arr[Left++];
                        if(current->left!=nullptr)
                        {
                            arr[Right++]=current->left;
                        }
                        if(current->right!=nullptr)
                        {
                            arr[Right++]=current->right;
                        }
                    }
                    ans.push_back(level);
                    reverse=!reverse;       
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
    
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(5, node7, node8);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3, nullptr, node6);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* root1 = new TreeNode(1, node2, node3);
    
    Solution solution;
    vector<vector<int>> result = solution.Function(root1);
    
    // Print the result
    cout << "Zigzag Level Order Traversal (Test Case 1):" << endl;
    cout << "Expected: [[1], [3, 2], [4, 5, 6], [8, 7]]" << endl;
    cout << "Actual:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test Case 2: Single node tree
    TreeNode* singleNode = new TreeNode(10);
    result = solution.Function(singleNode);
    cout << "Test Case 2 (Single node):" << endl;
    cout << "Expected: [[10]]" << endl;
    cout << "Actual:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl << endl;
    
    // Test Case 3: Empty tree
    TreeNode* emptyTree = nullptr;
    result = solution.Function(emptyTree);
    cout << "Test Case 3 (Empty tree):" << endl;
    cout << "Expected: []" << endl;
    cout << "Actual:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl << endl;
    
    // Test Case 4: Perfect binary tree
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    
    TreeNode* node7_perfect = new TreeNode(7);
    TreeNode* node6_perfect = new TreeNode(6);
    TreeNode* node5_perfect = new TreeNode(5);
    TreeNode* node4_perfect = new TreeNode(4);
    TreeNode* node3_perfect = new TreeNode(3, node6_perfect, node7_perfect);
    TreeNode* node2_perfect = new TreeNode(2, node4_perfect, node5_perfect);
    TreeNode* root_perfect = new TreeNode(1, node2_perfect, node3_perfect);
    
    result = solution.Function(root_perfect);
    cout << "Test Case 4 (Perfect binary tree):" << endl;
    cout << "Expected: [[1], [3, 2], [4, 5, 6, 7]]" << endl;
    cout << "Actual:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test Case 5: Left-skewed tree
    //       7
    //      /
    //     8
    //    /
    //   9
    //  /
    // 10
    
    TreeNode* node10_left = new TreeNode(10);
    TreeNode* node9_left = new TreeNode(9, node10_left, nullptr);
    TreeNode* node8_left = new TreeNode(8, node9_left, nullptr);
    TreeNode* root_left = new TreeNode(7, node8_left, nullptr);
    
    result = solution.Function(root_left);
    cout << "Test Case 5 (Left-skewed tree):" << endl;
    cout << "Expected: [[7], [8], [9], [10]]" << endl;
    cout << "Actual:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test Case 6: Right-skewed tree
    //       1
    //        \
    //         2
    //          \
    //           3
    //            \
    //             4
    
    TreeNode* node4_right = new TreeNode(4);
    TreeNode* node3_right = new TreeNode(3, nullptr, node4_right);
    TreeNode* node2_right = new TreeNode(2, nullptr, node3_right);
    TreeNode* root_right = new TreeNode(1, nullptr, node2_right);
    
    result = solution.Function(root_right);
    cout << "Test Case 6 (Right-skewed tree):" << endl;
    cout << "Expected: [[1], [2], [3], [4]]" << endl;
    cout << "Actual:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;
    
    // Test Case 7: Tree with only left children at some levels
    //       1
    //      / \
    //     2   3
    //    /   /
    //   4   5
    //      /
    //     6
    
    TreeNode* node6_special = new TreeNode(6);
    TreeNode* node5_special = new TreeNode(5, node6_special, nullptr);
    TreeNode* node4_special = new TreeNode(4);
    TreeNode* node3_special = new TreeNode(3, node5_special, nullptr);
    TreeNode* node2_special = new TreeNode(2, node4_special, nullptr);
    TreeNode* root_special = new TreeNode(1, node2_special, node3_special);
    
    result = solution.Function(root_special);
    cout << "Test Case 7 (Special tree):" << endl;
    cout << "Expected: [[1], [3, 2], [4, 5], [6]]" << endl;
    cout << "Actual:   [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Note: There might be a bug in your implementation
    // The current code doesn't properly collect values in zigzag order
    // You'll need to fix the logic in the Function method
    
    return 0;
}