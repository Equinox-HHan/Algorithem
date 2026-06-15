#include<bits/stdc++.h>
using namespace std;
//按层序列化和反序列化
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
            if(Head==nullptr)
            {
                return "";
            }
            string res="";
            res+=to_string(Head->value)+",";
            queue<TreeNode*> QUEUE;
            QUEUE.push(Head);
            while(!QUEUE.empty())
            {
                TreeNode *current=QUEUE.front();
                QUEUE.pop();
                if(current->left!=nullptr)
                {
                    QUEUE.push(current->left);
                    res+=to_string(current->left->value)+",";
                }
                else
                {
                    res+="#";
                }
                if(current->right!=nullptr)
                {
                    QUEUE.push(current->right);
                    res+=to_string(current->right->value)+",";
                }
                else
                {
                    res+="#";
                }
            }
            return res;
        }
        TreeNode* Deserialize(string data)
        {
            if(data.empty())
            {
                return nullptr;
            }
            stringstream ss(data);
            string input;
            vector<string> arr;
            while(getline(ss,input,','))
            {
                if(!input.empty())
                {
                    arr.push_back(input);
                }
            }
            //bfs重建二叉树
            int index=0;
            TreeNode *root=generate(arr[index]);
            queue<TreeNode*> Queue;
            if(root!=nullptr)
            {
                Queue.push(root);
            }
            while(!Queue.empty())
            {
                TreeNode *current=Queue.front();
                Queue.pop();
                current->left=generate(arr[index++]);
                current->right=generate(arr[index++]);
                if(current->left!=nullptr)
                {
                    Queue.push(current->left);
                }   
                if(current->right!=nullptr)
                {
                    Queue.push(current->right);
                }
            } 
        }
    private:
        TreeNode* generate(string &str)
        {
            if(str=="")
            {
                return nullptr;
            }
            else
            {
                return new TreeNode(stoi(str));
            }
        }
};
void printTree(TreeNode *Head)
{
    if(Head==nullptr)
    {
        return;
    }
    queue<TreeNode*> QQ;
    QQ.push(Head);
    while(!QQ.empty())
    {
        TreeNode *current=QQ.front();
        QQ.pop();
        if(current!=nullptr)
        {
            cout<<current->value<<endl;
            QQ.push(current->left);
            QQ.push(current->right);
        }
        else
        {
            cout<<"#"<<endl;
        }
    }
    return;
}