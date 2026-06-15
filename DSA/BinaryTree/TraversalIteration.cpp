#include<bits/stdc++.h>
using namespace std;
//迭代实现三种二叉树遍历
class TreeNode
{
    public:
        int value;
        TreeNode *leftNode;
        TreeNode *rightNode;
        TreeNode(int number)
        {
            value=number;
            leftNode=nullptr;
            rightNode=nullptr;
        }
        void preOrder(TreeNode *Head)
        {
            if(Head!=nullptr)
            {
                stack<TreeNode*> stack;
                stack.push(Head);
                while(!stack.empty())
                {
                    Head=stack.top();
                    stack.pop();
                    cout<<Head->value<<" ";
                    if(Head->rightNode!=nullptr)
                    {
                        stack.push(Head->rightNode);
                    }
                    if(Head->leftNode!=nullptr)
                    {
                        stack.push(Head->leftNode);
                    }
                }
            }
            cout<<endl;
        }
        void inOrder(TreeNode *Head)
        {
            if(Head!=nullptr)
            {
                stack<TreeNode*> stack;
                while(!stack.empty()||Head!=nullptr)
                {
                    if(Head!=nullptr)
                    {
                        stack.push(Head);
                        Head=Head->leftNode;
                    }
                    else
                    {
                        Head=stack.top();
                        stack.pop();
                        cout<<Head->value<<" ";
                        Head=Head->rightNode;
                    }
                }
            }
            cout<<endl;
        }
        void postOrder(TreeNode *Head)
        {
            if(Head!=nullptr)
            {
                stack<TreeNode*> stack;
                stack.push(Head);
                while(!stack.empty())
                {
                    TreeNode *current=stack.top();
                    if(current->leftNode!=nullptr&&Head!=current->leftNode&&Head!=current->rightNode)
                    {
                        stack.push(current->leftNode);
                    }
                    else if(current->rightNode!=nullptr&&Head!=current->rightNode)
                    {
                        stack.push(current->rightNode);
                    }
                    else
                    {
                        cout<<current->value<<" ";
                        Head=stack.top();
                        stack.pop();
                    }
                }
            }
            cout<<endl;
        }
        void DoubleStackinOrder(TreeNode *Head)
        {
            stack<TreeNode*> stack1;
            stack<TreeNode*> stack2;
            stack1.push(Head);
            while(!stack1.empty())
            {
                Head=stack1.top();
                stack1.pop();
                stack2.push(Head);
                if(Head->leftNode!=nullptr)
                {
                    stack1.push(Head->leftNode);
                }
                if(Head->rightNode!=nullptr)
                {
                    stack1.push(Head->rightNode);
                }
            }
            while(!stack2.empty())
            {
                cout<<stack2.top()->value<<" ";
                stack2.pop();
            }
            cout<<endl;
        }
};
int main()
{
    TreeNode *Head=new TreeNode(1);
    Head->leftNode=new TreeNode(2);
    Head->rightNode=new TreeNode(3);
    Head->leftNode->leftNode=new TreeNode(4);
    Head->leftNode->rightNode=new TreeNode(5);
    cout<<"Preorder Traversal: ";
    Head->preOrder(Head);
    cout<<"Inorder Traversal: ";
    Head->inOrder(Head);
    cout<<"Postorder Traversal: ";
    Head->postOrder(Head);
    cout<<"Double Stack Inorder Traversal: ";
    Head->DoubleStackinOrder(Head);
    return 0;
}