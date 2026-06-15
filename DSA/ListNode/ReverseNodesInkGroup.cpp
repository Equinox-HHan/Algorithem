#include<bits/stdc++.h>
using namespace std;
class ListNode
{   
    public:
        int val;
        ListNode *next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x, ListNode *next): val(x), next(next) {}
};
class Solution
{
    public:
        void reverse(ListNode *A,ListNode *E)
        {
            E=E->next;
            ListNode *pre=nullptr,*next=nullptr,*current=A;
            while(current!=E)
            {
                next=current->next;
                current->next=pre;
                pre=current;
                current=next;
            }
            A->next=E;
        }
        ListNode *TeamEnd(ListNode *Head,int k)
        {
            while(Head!=nullptr && k-->0)
            {
                Head=Head->next;
            }
            return Head;
        }
        ListNode *reverseKGroup(ListNode *Head,int k)
        {
            ListNode *start=Head;
            ListNode *end=TeamEnd(Head,k);
            if(end==nullptr)
            {
                return Head;
            }
            Head=end;
            reverse(start,end);
            ListNode *lastTeamEnd=start;
            while(lastTeamEnd->next!=nullptr)
            {
                start=lastTeamEnd->next;
                end=TeamEnd(start,k);
                if(end==nullptr)
                {
                    return Head;
                }
                reverse(start,end);
                lastTeamEnd->next=end;
                lastTeamEnd=start;
            }
            return Head;
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
    Solution s;
    Head=s.reverseKGroup(Head,3);
    while(Head!=nullptr)
    {
        cout<<Head->val<<" ";
        Head=Head->next;
    }
    delete Head;
    return 0;
}