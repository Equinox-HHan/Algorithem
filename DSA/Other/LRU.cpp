#include<bits/stdc++.h>
using namespace std;
class LRUCACHE
{
    private:
        struct DoubleNode//双向链表节点的定义
        {
            int Key;
            int Value;
            DoubleNode *last;
            DoubleNode *next;
            DoubleNode(int key,int value)
            {
                Key=key;
                Value=value;
                last=nullptr;
                next=nullptr;
            }
        };
        class DoubleListNode//对双向链表的管理函数
        {
            private:
                DoubleNode *Head;
                DoubleNode *End;
            public:
                DoubleListNode()
                {
                    Head=nullptr;
                    End=nullptr;
                }
                DoubleNode *RemoveHead()
                {
                    if(Head==nullptr)
                    {
                        return nullptr;
                    }
                    DoubleNode *ans=Head;
                    if(Head==End)
                    {
                        Head=nullptr;
                        End=nullptr;
                    }
                    else
                    {
                        Head=ans->next;
                        ans->next=nullptr;
                        Head->last=nullptr;    
                    }
                    return ans;
                }
                void AppendNode(DoubleNode *node)
                {
                    if(node==nullptr)
                    {
                        return;
                    }
                    if(Head==nullptr)
                    {
                        Head=node;
                        End=node;
                    }
                    else
                    {
                        End->next=node;
                        node->last=End;
                        End=node;
                    }
                }
                void moveNodeEnd(DoubleNode *node)
                {
                    if(node==End)
                    {
                        return;
                    }
                    if(node==Head)
                    {
                        node->next=Head;
                        Head->last=nullptr;
                    }
                    else
                    {
                        node->last->next=node->next;
                        node->next->last=node->last;
                    }
                    End->next=node;
                    node->last=End;
                    node->next=nullptr;
                    End=node;
                }
                void clear()
                {
                    DoubleNode *cur=Head;
                    while(cur!=nullptr)
                    {
                        DoubleNode *Nextpoint=cur->next;
                        delete cur;
                        cur=Nextpoint;
                    }
                }
        };
        unordered_map<int,DoubleNode*> Hashmap;
        DoubleListNode ListNode;
        int capacity;
    public:
        LRUCACHE(int number)
        {
            capacity=number;
        }
        ~LRUCACHE()
        {
            ListNode.clear();
        }
        int getElement(int key)
        {
            if(Hashmap.find(key)==Hashmap.end())
            {
                return -1;
            }
            DoubleNode *ans=Hashmap[key];
            ListNode.moveNodeEnd(ans);
            return ans->Value;
        }
        void putElement(int key,int value)
        {
            if(Hashmap.find(key)!=Hashmap.end())
            {
                DoubleNode *node=Hashmap[key];
                node->Value=value;
                ListNode.moveNodeEnd(node);
            }
            else
            {
                if(Hashmap.size()==capacity)
                {
                    DoubleNode *moveNode=ListNode.RemoveHead();
                    Hashmap.erase(moveNode->Key);
                    delete moveNode;
                }
                DoubleNode *newNode=new DoubleNode(key,value);
                Hashmap[key]=newNode;
                ListNode.AppendNode(newNode);
            }
        }
};
int main()
{
    return 0;
}