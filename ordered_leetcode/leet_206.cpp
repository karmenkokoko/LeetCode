#include <bits/stdc++.h>

using namespace std;

// 反转链表

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
    ListNode* reverseList(ListNode* head) {
        // prev和cur指针
        ListNode *prev = nullptr;
        ListNode *cur = head;
        // 迭代
        while(cur)
        {
            ListNode *new_node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = new_node;
        }
        // 返回prev
        return prev;
    }
};