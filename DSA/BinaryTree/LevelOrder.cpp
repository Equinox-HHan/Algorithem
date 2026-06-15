#include<bits/stdc++.h>
using namespace std;
//实现二叉树的层序遍历，按从左到右的顺序以数组形式输出
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
class Traversal
{
    public:
        static const int maxNumber=20;
        TreeNode* QUEUE[maxNumber];
        int Left,Right;
        vector<vector<int>> levelOrder(TreeNode *root)
        {
            vector<vector<int>> ans;
            if(root!=nullptr)
            {
                Left=Right=0;
                QUEUE[Right++]=root;
                while(Left<Right)
                {
                    int size=Right-Left;
                    vector<int> levelList;
                    for(int i=0;i<size;i++)
                    {
                        TreeNode *current=QUEUE[Left++];
                        levelList.push_back(current->value);
                        if(current->left!=nullptr)
                        {
                            QUEUE[Right++]=current->left;
                        }
                        if(current->right!=nullptr)
                        {
                            QUEUE[Right++]=current->right;
                        }
                    }
                    ans.push_back(levelList);
                }
            }
            return ans;
        }
};
#include<bits/stdc++.h>
using namespace std;

// ... (your existing TreeNode and Traversal class code here) ...

int main() {
    // Test Case 1: Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3, nullptr, node6);
    TreeNode* node2 = new TreeNode(2, node4, node5);
    TreeNode* root1 = new TreeNode(1, node2, node3);
    
    // Test the level order traversal
    Traversal traversal;
    vector<vector<int>> result = traversal.levelOrder(root1);
    
    // Print the result
    cout << "Level Order Traversal (Test Case 1):" << endl;
    cout << "Expected: [[1], [2, 3], [4, 5, 6]]" << endl;
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
    result = traversal.levelOrder(singleNode);
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
    result = traversal.levelOrder(emptyTree);
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
    
    // Test Case 4: Left-skewed tree
    //       7
    //      /
    //     8
    //    /
    //   9
    TreeNode* node9_left = new TreeNode(9);
    TreeNode* node8_left = new TreeNode(8, node9_left, nullptr);
    TreeNode* root2_left = new TreeNode(7, node8_left, nullptr);
    
    result = traversal.levelOrder(root2_left);
    cout << "Test Case 4 (Left-skewed tree):" << endl;
    cout << "Expected: [[7], [8], [9]]" << endl;
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
    
    // Test Case 5: Right-skewed tree
    //       1
    //        \
    //         2
    //          \
    //           3
    TreeNode* node3_right = new TreeNode(3);
    TreeNode* node2_right = new TreeNode(2, nullptr, node3_right);
    TreeNode* root2_right = new TreeNode(1, nullptr, node2_right);
    
    result = traversal.levelOrder(root2_right);
    cout << "Test Case 5 (Right-skewed tree):" << endl;
    cout << "Expected: [[1], [2], [3]]" << endl;
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
    
    // Test Case 6: Complete binary tree
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4   5 6   7
    TreeNode* node7_complete = new TreeNode(7);
    TreeNode* node6_complete = new TreeNode(6);
    TreeNode* node5_complete = new TreeNode(5);
    TreeNode* node4_complete = new TreeNode(4);
    TreeNode* node3_complete = new TreeNode(3, node6_complete, node7_complete);
    TreeNode* node2_complete = new TreeNode(2, node4_complete, node5_complete);
    TreeNode* root_complete = new TreeNode(1, node2_complete, node3_complete);
    
    result = traversal.levelOrder(root_complete);
    cout << "Test Case 6 (Complete binary tree):" << endl;
    cout << "Expected: [[1], [2, 3], [4, 5, 6, 7]]" << endl;
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
    
    // Clean up memory (optional, but good practice)
    // Note: In a real application, you'd want to properly delete all nodes
    // For simplicity, we're not implementing a full cleanup here
    
    return 0;
}