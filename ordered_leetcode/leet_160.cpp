#include <bits/stdc++.h>

using namespace std;

// 相交链表

// 遍历两个链表, 两个指针交汇

class Solution{
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA, *B = headB;
        while(A!=B)
        {
            if(A==nullptr)
            {
                A = headB;
            }
            else{
                A = A->next;
            }
            if(B==nullptr)
            {
                B = headA;
            }
            else{
                B = B->next;
            }
        }
        return A;
    }
};