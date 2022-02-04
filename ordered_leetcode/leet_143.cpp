#include <bits/stdc++.h>

using namespace std;
// 143. 重排链表
// 分段， 反转， 合并

class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* mid = split(head);
        ListNode* l1 = head;
        ListNode* l2 = mid;

        l2 = reverse(l2);
        merge(l1, l2);
    }

    ListNode* split(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

        }
        return prev;
    }
    void merge(ListNode* l1, ListNode* l2)
    {
        ListNode *l1_tmp, *l2_tmp;
        while (l1 && l2) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }

};