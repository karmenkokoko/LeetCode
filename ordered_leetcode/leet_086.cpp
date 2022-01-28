#include <bits/stdc++.h>

using namespace std;

// 分割链表， 给定x, 把小于x的放在前面，大于x的放在后面
// 创建两个链表即可

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode();
        ListNode* greater = new ListNode();

        ListNode* l = less, *g = greater;

        while(head)
        {
            if(head->val < x)
            {
                l->next = new ListNode(head->val);
                l = l->next;
                head = head->next;
            }
            else{
                g->next = new ListNode(head->val);
                g = g->next;
                head = head->next;
            }
        }
        l->next = greater->next;

        return less->next;
    }
};