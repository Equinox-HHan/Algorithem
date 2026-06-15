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
        vector<vector<int>> pathSumll(TreeNode *Head,int targetNumber)
        {
            vector<vector<int>> ans;
            if(Head==nullptr)
            {
                return ans;
            }
            vector<int> path;
            Function(Head,targetNumber,0,ans,path);
            return ans;
        }
    private:
        void Function(TreeNode *cur,int Number,int sum,vector<vector<int>> &ans,vector<int> &path)
        {
            path.push_back(cur->value);
            if(cur->left==nullptr&&cur->right==nullptr)
            {
                if((cur->value+sum)==Number)
                {
                    ans.push_back(path);
                }
            }
            else
            {
                if(cur->left!=nullptr)
                {
                    Function(cur->left,Number,sum+cur->value,ans,path);
                }
                if(cur->right!=nullptr)
                {
                    Function(cur->right,Number,sum+cur->value,ans,path);
                }
            }
        }
};
#include <iostream>
#include <vector>
using namespace std;

// Your existing TreeNode and Solution class would be here

int main() {
    Solution solution;
    
    // Test Case 1: Basic tree with multiple paths
    //       5
    //      / \
    //     4   8
    //    /   / \
    //   11  13  4
    //  /  \      \
    // 7    2      1
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->right = new TreeNode(1);
    
    int target1 = 22;
    cout << "Test Case 1 - Target Sum: " << target1 << endl;
    vector<vector<int>> result1 = solution.pathSumll(root1, target1);
    cout << "Number of paths: " << result1.size() << endl;
    cout << "Paths:" << endl;
    for (const auto& path : result1) {
        cout << "[";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Expected: [[5,4,11,2], [5,8,4,5]]" << endl << endl;
    
    // Test Case 2: Single node tree
    TreeNode* root2 = new TreeNode(10);
    int target2 = 10;
    cout << "Test Case 2 - Target Sum: " << target2 << endl;
    vector<vector<int>> result2 = solution.pathSumll(root2, target2);
    cout << "Number of paths: " << result2.size() << endl;
    for (const auto& path : result2) {
        cout << "[";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Expected: [[10]]" << endl << endl;
    
    // Test Case 3: Single node with non-matching sum
    int target3 = 5;
    cout << "Test Case 3 - Target Sum: " << target3 << endl;
    vector<vector<int>> result3 = solution.pathSumll(root2, target3);
    cout << "Number of paths: " << result3.size() << endl;
    cout << "Expected: []" << endl << endl;
    
    // Test Case 4: Empty tree
    TreeNode* root4 = nullptr;
    int target4 = 0;
    cout << "Test Case 4 - Target Sum: " << target4 << endl;
    vector<vector<int>> result4 = solution.pathSumll(root4, target4);
    cout << "Number of paths: " << result4.size() << endl;
    cout << "Expected: []" << endl << endl;
    
    // Test Case 5: Tree with negative values
    //      -5
    //      / \
    //     2   3
    //    / \   \
    //   1   4   -2
    TreeNode* root5 = new TreeNode(-5);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(4);
    root5->right->right = new TreeNode(-2);
    
    int target5 = -2;
    cout << "Test Case 5 - Target Sum: " << target5 << endl;
    vector<vector<int>> result5 = solution.pathSumll(root5, target5);
    cout << "Number of paths: " << result5.size() << endl;
    for (const auto& path : result5) {
        cout << "[";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Expected: [[-5,2,1], [-5,3]]" << endl << endl;
    
    // Test Case 6: Tree with only left children
    //    1
    //     \
    //      2
    //       \
    //        3
    //         \
    //          4
    TreeNode* root6 = new TreeNode(1);
    root6->right = new TreeNode(2);
    root6->right->right = new TreeNode(3);
    root6->right->right->right = new TreeNode(4);
    
    int target6 = 10;
    cout << "Test Case 6 - Target Sum: " << target6 << endl;
    vector<vector<int>> result6 = solution.pathSumll(root6, target6);
    cout << "Number of paths: " << result6.size() << endl;
    for (const auto& path : result6) {
        cout << "[";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Expected: [[1,2,3,4]]" << endl << endl;
    
    // Test Case 7: Multiple paths with same sum
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5
    TreeNode* root7 = new TreeNode(1);
    root7->left = new TreeNode(2);
    root7->right = new TreeNode(3);
    root7->left->left = new TreeNode(4);
    root7->right->right = new TreeNode(5);
    
    int target7 = 7;
    cout << "Test Case 7 - Target Sum: " << target7 << endl;
    vector<vector<int>> result7 = solution.pathSumll(root7, target7);
    cout << "Number of paths: " << result7.size() << endl;
    for (const auto& path : result7) {
        cout << "[";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "Expected: [[1,2,4], [1,3,5? (but 1+3+5=9 not 7)]] Actually [[1,2,4]]" << endl << endl;
    
    // Clean up memory (optional but good practice)
    // You can add a delete function to clean up all nodes
    
    return 0;
}