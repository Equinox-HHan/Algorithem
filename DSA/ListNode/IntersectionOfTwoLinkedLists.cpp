#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
        int val;
        ListNode *next;
        ListNode():val(0),next(nullptr){}
        ListNode(int val):val(val),next(nullptr){}
        ListNode(int val,ListNode *next):val(val),next(next){}
};
class Solution
{
    public:
        ListNode *getIntersectionNode(ListNode *headA,ListNode *headB)
        {
            if(headA==nullptr||headB==nullptr)
            {
                return nullptr;
            }
            ListNode *curA=headA;
            ListNode *curB=headB;
            int distance=0;
            while(curA!=nullptr)
            {
                distance+=1;
                curA=curA->next;
            }
            while(curB!=nullptr)
            {
                distance-=1;
                curB=curB->next;
            }
            if(curA!=curB)
            {
                return nullptr;
            }
            if(distance>=0)
            {
                //A长度较长B长度较短
                curA=headA;
                curB=headB;
            }
            else
            {
                //B长度较长A长度较短
                curB=headA;
                curA=headB;
            }
            //让较长的链表A先走distance步
            distance=abs(distance);
            while(distance>0)
            {
                distance-=1;
                curA=curA->next;
            }
            //让A和B一起走，直到相交
            while(curA!=curB)
            {
                curA=curA->next;
                curB=curB->next;
            }
            return curA;
        }
};
int main()
{
    ListNode *headA=new ListNode(4);
    headA->next=new ListNode(1);
    ListNode *headB=new ListNode(5);
    headB->next=new ListNode(0);
    headB->next->next=new ListNode(1);
    headA->next->next=new ListNode(8);
    headA->next->next->next=new ListNode(4);
    headA->next->next->next->next=new ListNode(5);
    headB->next->next->next=headA->next->next;
    Solution *solution=new Solution();
    ListNode *intersection=solution->getIntersectionNode(headA,headB);
    if(intersection!=nullptr)
    {
        cout<<intersection->val<<endl;
    }
    else
    {
        cout<<"No intersection"<<endl;
    }
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB->next->next;
    delete headB->next;
    delete headB;
    delete solution;
    return 0;
}