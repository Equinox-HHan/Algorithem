#include<bits/stdc++.h>
#include "ListNode.cpp"
using namespace std;

ListNode *MergeListNode(ListNode *head1,ListNode *head2)
{
    if(head1==nullptr||head2==nullptr)
    {
        return head1==nullptr?head2:head1;
    }
    ListNode *head=head1->val<=head2->val?head1:head2;
    ListNode *cur1=head->next;
    ListNode *cur2=head==head1?head2:head1;
    ListNode *pre=head;
    while(cur1!=nullptr&&cur2!=nullptr)
    {
        if(cur1->val<=cur2->val)
        {
            pre->next=cur1;
            cur1=cur1->next;
        }
        else
        {
            pre->next=cur2;
            cur2=cur2->next;
        }
        pre=pre->next;
    }
    pre->next=cur1==nullptr?cur2:cur1;
    return head;
}

ListNode *AddListNode(ListNode *head1,ListNode *head2)
{
    ListNode *cur=nullptr;
    ListNode *ans=nullptr;
    int number,summary;
    int carry=0;
    for(;head1!=nullptr||head2!=nullptr;head1=head1==nullptr?nullptr:head1->next,head2=head2==nullptr?nullptr:head2->next)
    {
        int addNumber1=head1==nullptr?0:head1->val;
        int addNumber2=head2==nullptr?0:head2->val;
        summary=addNumber1+addNumber2+carry;
        number=summary%10;
        carry=summary/10;
        if(ans==nullptr)
        {
            ans=new ListNode(number);
            cur=ans;
        }
        else
        {
            cur->next=new ListNode(number);
            cur=cur->next;
        }
    }
    if(carry!=0)
    {
        cur->next=new ListNode(carry);
    }
    return ans;
}

ListNode *PartionListNode(ListNode *head,int x)
{
    ListNode *lefthead=nullptr;ListNode *lefttail=nullptr;
    ListNode *righthead=nullptr;ListNode *righttail=nullptr;
    ListNode *next=nullptr;
    while(head!=nullptr)
    {
        next=head->next;
        head->next=nullptr;
        if(head->val<=x)
        {
            if(lefthead==nullptr)
            {
                lefthead=head;
            }
            else
            {
                lefttail->next=head;
            }
            lefttail=head;
        }
        else
        {
            if(righthead==nullptr)
            {
                righthead=head;
            }
            else
            {
                righttail->next=head;
            }
            righttail=head;
        }
        head=next;
    }
    if(lefthead==nullptr)
    {
        return righthead;
    }
    lefttail->next=righthead;
    return lefthead;
}

int main()
{
    ListNode *head1=new ListNode(1);
    head1->next=new ListNode(3);
    head1->next->next=new ListNode(5);
    ListNode *head2=new ListNode(2);
    head2->next=new ListNode(4);
    head2->next->next=new ListNode(6);
    ListNode *mergehead=MergeListNode(head1,head2);
    while(mergehead!=nullptr)
    {
        cout<<mergehead->val<<" ";
        mergehead=mergehead->next;
    }

    ListNode *addhead1=new ListNode(2);
    addhead1->next=new ListNode(4);
    addhead1->next->next=new ListNode(3);
    ListNode *addhead2=new ListNode(5);
    addhead2->next=new ListNode(6);
    addhead2->next->next=new ListNode(4);
    ListNode *addhead=AddListNode(addhead1,addhead2);
    cout<<endl;
    while(addhead!=nullptr)
    {
        cout<<addhead->val<<" ";
        addhead=addhead->next;
    }

    ListNode *partionhead=new ListNode(1);
    partionhead->next=new ListNode(4);
    partionhead->next->next=new ListNode(3);
    partionhead->next->next->next=new ListNode(2);
    partionhead->next->next->next->next=new ListNode(5);
    partionhead->next->next->next->next->next=new ListNode(2);
    ListNode *partionedhead=PartionListNode(partionhead,3);
    cout<<endl;
    while(partionedhead!=nullptr)
    {
        cout<<partionedhead->val<<" ";
        partionedhead=partionedhead->next;
    }
    delete mergehead;
    delete addhead;
    delete partionedhead;
    delete head1;
    delete head2;
    delete addhead1;
    delete addhead2;
    delete partionhead;
    return 0;
}