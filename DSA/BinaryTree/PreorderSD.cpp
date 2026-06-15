#include<bits/stdc++.h>
using namespace std;
//二叉树的先序序列化和反序列化
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
        string Serialize(TreeNode *Head)
        {
            string res="";
            function(Head,res);
            return res;
        } 
        void function(TreeNode *Head,string &res)
        {
            if(Head==nullptr)
            {
                res+="#,";
            }
            else
            {
                res+=to_string(Head->value)+",";
                function(Head->left,res);
                function(Head->right,res);
            }
        }
        TreeNode *Deserialize(string data)
        {
            if(data.empty())
            {
                return nullptr;
            }
            stringstream ss(data);
            string input;
            vector<string> vals;
            while(getline(ss,input,','))
            {
                if(!input.empty())
                {
                    vals.push_back(input);
                }
            }
            int count=0;
            return gunction(vals,count);
        }
        TreeNode* gunction(vector<string> &vals,int &count)
        {
            string current=vals[count++];
            if(current=="#")
            {
                return nullptr;
            }
            else
            {
                TreeNode *Head=new TreeNode(stoi(current));
                Head->left=gunction(vals,count);
                Head->right=gunction(vals,count);
                return Head;
            }
        }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution ser, deser;
    string data = ser.Serialize(root);
    cout << "Serialized: " << data << endl; // 1,2,#,#,3,4,#,#,5,#,#,

    TreeNode* ans = deser.Deserialize(data);
    cout << "Deserialized root val: " << ans->value << endl;

    return 0;
}