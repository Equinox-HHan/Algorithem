#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val=x;
        next=nullptr;
    }
};
class  Solution
{
    public:
    struct Compare
    {
        bool operator()(ListNode* a,ListNode* b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKList(vector<ListNode*>& Lists)
    {
        priority_queue<ListNode*,vector<ListNode*>,Compare> Heap;
        for(ListNode* node:Lists)
        {
            if(node!=nullptr)
            {
                Heap.push(node);
            }
        }
        if(Heap.empty())
        {
            return nullptr;
        }
        ListNode* head=Heap.top();
        Heap.pop();
        ListNode* pre=head;
        if(pre->next!=nullptr)
        {
            Heap.push(pre->next);
        }
        while(!Heap.empty())
        {
            ListNode* cur=Heap.top();
            Heap.pop();
            pre->next=cur;
            pre=cur;
            if(cur->next!=nullptr)
            {
                Heap.push(cur->next);
            }
        }
        return head;
    }
};
int main()
{
    ListNode* node1=new ListNode(1);
    ListNode* node2=new ListNode(4);
    ListNode* node3=new ListNode(5);
    node1->next=node2;
    node2->next=node3;
    ListNode* node4=new ListNode(1);
    ListNode* node5=new ListNode(3);
    ListNode* node6=new ListNode(4);
    node4->next=node5;
    node5->next=node6;
    ListNode* node7=new ListNode(2);
    ListNode* node8=new ListNode(6);
    node7->next=node8;
    vector<ListNode*> Lists={node1,node4,node7};
    Solution solution;
    ListNode* head=solution.mergeKList(Lists);
    while(head!=nullptr)    
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}