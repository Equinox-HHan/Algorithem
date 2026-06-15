#include<bits/stdc++.h>
#include "ListNode.cpp"
using namespace std;
ListNode *reverseListNode(ListNode *head)
{
    ListNode *pre=nullptr;
    ListNode *next=nullptr;
    while(head!=nullptr)
    {
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}
DoubleListNode *reverseDoubleListNode(DoubleListNode *head)
{
    DoubleListNode *pre=nullptr;
    DoubleListNode *next=nullptr;
    while(head!=nullptr)
    {
        next=head->next;
        head->next=pre;
        head->pre=next;
        pre=head;
        head=next;
    }
    return pre;
}
int main()
{
    ListNode* node2=new ListNode(2); 
    ListNode* node1=new ListNode(1); 
    node1->next=node2;
    ListNode *newHead=reverseListNode(node1);
    cout<<newHead->val<<" "<<newHead->next->val<<endl;

    DoubleListNode* dnode2=new DoubleListNode(2); 
    DoubleListNode* dnode1=new DoubleListNode(1); 
    dnode1->next=dnode2;
    dnode2->pre=dnode1;
    DoubleListNode *dnewHead=reverseDoubleListNode(dnode1);
    cout<<dnewHead->val<<" "<<dnewHead->next->val<<endl;
    delete node1;
    delete node2;
    delete dnode1;
    delete dnode2;
    delete newHead;
    delete dnewHead;
    return 0;
}