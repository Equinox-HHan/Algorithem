#include<bits/stdc++.h>
using namespace std;
class ListNode
{   
    public:
        int val;
        ListNode *next;
        ListNode *random;
        ListNode(int number):val(number),next(nullptr),random(nullptr){}
};
class Solution
{
    public:
        ListNode *copyRandomList(ListNode *Head)
        {
            if(Head==nullptr)
            {
                return nullptr;
            }
            ListNode *cur=Head;
            ListNode *Next=nullptr;
            while(cur!=nullptr)
            {
                Next=cur->next;
                cur->next=new ListNode(cur->val);
                cur->next->next=Next;
                cur=Next;
            }
            cur=Head;
            ListNode *copy=nullptr;
            while(cur!=nullptr)
            {
                Next=cur->next->next;
                copy=cur->next;
                copy->random=(cur->random!=nullptr)?cur->random->next:nullptr;
                cur=Next;
            }
            cur=Head;
            ListNode *ans=Head->next;
            while(cur!=nullptr)
            {
                Next=cur->next->next;
                copy=cur->next;
                copy->next=(Next->next!=nullptr)?Next->next:nullptr;
                cur->next=Next;
                cur=Next;
            }
            return ans;
        }
};
int main()
{
    ListNode *Head=new ListNode(1);
    ListNode *temp=Head;
    for(int i=2;i<=10;i++)
    {
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    delete temp;
    delete Head;
    return 0;
}