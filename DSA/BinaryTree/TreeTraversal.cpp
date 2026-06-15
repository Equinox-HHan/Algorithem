#include<bits/stdc++.h>
using namespace std;
//递归实现三种二叉树遍历
class Traversal
{
    public:
        Traversal(int value)
        {
            this->value=value;
            leftNode=nullptr;
            rightNode=nullptr;
        }
        void preOrder(Traversal *Head)
        {
            if(Head==nullptr)
            {
                return;
            }
            cout<<Head->value<<" ";
            preOrder(Head->leftNode);
            preOrder(Head->rightNode);
        }
        void inOrder(Traversal *Head)
        {
            if(Head==nullptr)
            {
                return;
            }
            inOrder(Head->leftNode);
            cout<<Head->value<<" ";
            inOrder(Head->rightNode);
        }
        void postOrder(Traversal *Head)
        {
            if(Head==nullptr)
            {
                return;
            }
            postOrder(Head->leftNode);
            postOrder(Head->rightNode);
            cout<<Head->value<<" ";
        }
        int value;
        Traversal *leftNode;
        Traversal *rightNode;
};
int main()
{  
    Traversal *Head=new Traversal(1);
    Head->leftNode=new Traversal(2);
    Head->rightNode=new Traversal(3);
    Head->leftNode->leftNode=new Traversal(4);
    Head->leftNode->rightNode=new Traversal(5);
    cout<<"Preorder Traversal: ";
    Head->preOrder(Head);
    cout<<"\nInorder Traversal: ";
    Head->inOrder(Head);
    cout<<"\nPostorder Traversal: ";
    Head->postOrder(Head);
    return 0;  
}