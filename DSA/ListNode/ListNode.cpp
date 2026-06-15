#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
        ListNode(int val):val(val),next(nullptr){}
        ListNode(int val,ListNode *next):val(val),next(next){}
        int val;
        ListNode *next;
};
class DoubleListNode
{
    public:
        DoubleListNode(int val):val(val),next(nullptr),pre(nullptr){}
        int val;
        DoubleListNode *next;
        DoubleListNode *pre;
};