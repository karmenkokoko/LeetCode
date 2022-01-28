#include <bits/stdc++.h>

using namespace std;

// 回文链表
// 快慢指针分割，反转后一个链表，比较.

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
    bool isPalindrome(ListNode* head) {
        ListNode* mid = split_list(head);
        ListNode* reversed_mid = reverse_list(mid);
        
        while(reversed_mid)
        {
            if(head->val != reversed_mid->val) return false;
            head = head->next;
            reversed_mid = reversed_mid->next;
        }
        return true;
    }

    ListNode* reverse_list(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = node;
        }
        return prev;
    }

    ListNode* split_list(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->next;
    }
};