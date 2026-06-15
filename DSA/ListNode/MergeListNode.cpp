#include <bits/stdc++.h>
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
    ListNode *Start;
    ListNode *End;
    ListNode *FindEnd(ListNode *Head, int k)
    {
        while (--k > 0 && Head != nullptr)
        {
            Head = Head->next;
        }
        return Head;
    }
    void Merge(ListNode *left1, ListNode *left2, ListNode *right1, ListNode *right2)
    {
        ListNode *pre;
        if (left1->val <= left2->val)
        {
            Start = left1;
            pre = left1;
            left1 = left1->next;
        }
        else
        {
            Start = left2;
            pre = left2;
            left2 = left2->next;
        }
        while (left1 != nullptr && left2 != nullptr)
        {
            if (left1->val <= left2->val)
            {
                pre->next = left1;
                pre = left1;
                left1 = left1->next;
            }
            else
            {
                pre->next = left2;
                pre = left2;
                left2 = left2->next;
            }
        }
        if (left1 != nullptr)
        {
            pre->next = left1;
            End = right1;
        }
        else
        {
            pre->next = left2;
            End = right2;
        }
    }
    ListNode *MergeListNode(ListNode *Head)
    {
        int n = 0;
        ListNode *cur = Head;
        while (cur != nullptr)
        {
            cur = cur->next;
            n += 1;
        }
        ListNode *l1, *l2, *r1, *r2;
        ListNode *Next, *LastTeamEnd;
        for (int step = 1; step < n; step <<= 1)
        {
            l1 = Head;
            r1 = FindEnd(l1, step);
            l2 = r1->next;
            r2 = FindEnd(l2, step);
            Next = r2->next;
            r1->next = nullptr;
            r2->next = nullptr;
            Merge(l1, l2, r1, r2);
            Head = Start;
            LastTeamEnd = End;
            while (Next != nullptr)
            {
                l1 = Next;
                r1 = FindEnd(l1, step);
                l2 = r1->next;
                if (l2 == nullptr)
                {
                    LastTeamEnd->next = l1;
                    break;
                }
                r2 = FindEnd(l2, step);
                Next = r2->next;
                r1->next = nullptr;
                r2->next = nullptr;
                Merge(l1, l2, r1, r2);
                LastTeamEnd->next = Start;
                LastTeamEnd = End;
            }
        }
        return Head;
    }
};
int main()
{
    // 构造链表
    ListNode *Head = new ListNode(4);
    Head->next = new ListNode(2);
    Head->next->next = new ListNode(1);
    Head->next->next->next = new ListNode(3);

    Solution s;
    Head = s.MergeListNode(Head);

    // 打印链表（注意保留 Head 指针用于后续删除）
    ListNode *printCur = Head;
    while (printCur != nullptr)
    {
        cout << printCur->val << " ";
        printCur = printCur->next;
    }
    cout << endl;

    // 修改：正确的内存释放逻辑
    ListNode *temp;
    while (Head != nullptr)
    {
        temp = Head;       // 1. 暂存当前节点
        Head = Head->next; // 2. Head 指向下一个
        delete temp;       // 3. 删除当前节点
    }

    return 0;
}