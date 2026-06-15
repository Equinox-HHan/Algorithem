#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
    public:
        ListNode *dectectCycle(ListNode *Head)
        {
            if(Head==nullptr||Head->next==nullptr||Head->next->next==nullptr)
            {
                return nullptr;
            }
            ListNode *slow=Head,*fast=Head;
            while(fast!=slow)
            {
                if(fast->next==nullptr||fast->next->next==nullptr)
                {
                    return nullptr;
                }
                slow=slow->next;
                fast=fast->next->next;
            }
            fast=Head;
            while(fast!=slow)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
};
int main()
{
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=head;
    Solution s;
    ListNode *cycleStart=s.dectectCycle(head);
    if(cycleStart)
    {
        cout<<"Cycle starts at node with value: "<<cycleStart->val<<endl;
    }
    else
    {
        cout<<"No cycle detected."<<endl;
    }
    return 0;
}