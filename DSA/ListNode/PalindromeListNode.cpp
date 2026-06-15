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
        bool isPalindrome(ListNode *Head)
        {
            if(Head==nullptr||Head->next==nullptr)
            {
                return true;
            }
            ListNode *slow=Head;
            ListNode *fast=Head;
            while(fast->next!=nullptr&&fast->next->next!=nullptr)
            {
                slow=slow->next;
                fast=fast->next->next;
            }
            ListNode *pre=slow;
            ListNode *cur=slow->next;
            ListNode *Next=nullptr;
            pre->next=nullptr;
            while(cur!=nullptr)
            {
                Next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=Next;
            }
            ListNode *left=Head;
            ListNode *right=pre;
            bool flag=true;
            while(left!=nullptr&&right!=nullptr)
            {
                if(left->val!=right->val)
                {
                    flag=false;
                    break;
                }
                left=left->next;
                right=right->next;
            }
            cur=pre->next;
            pre->next=nullptr;
            Next=nullptr;
            while(cur!=nullptr)
            {
                Next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=Next;
            }
            return flag;
        }
};
int main()
{
    ListNode *Head=new ListNode(1);
    Head->next=new ListNode(2);
    Head->next->next=new ListNode(2);
    Head->next->next->next=new ListNode(1);
    if(Solution().isPalindrome(Head))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    delete Head->next->next->next;
    delete Head->next->next;
    delete Head->next;
    delete Head;
    return 0;
}