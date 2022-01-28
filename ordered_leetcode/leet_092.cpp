#include <bits/stdc++.h>

using namespace std;

// 反转链表区间

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
    ListNode *reverseBetween(ListNode *head, int left, int right){
        // 用一个节点来记录反转区间之前的Node
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* hh = dummyhead;
        for(int i = 1; i < left; i++)
        {
            hh = hh->next;
        }
        ListNode* prev = hh->next;
        ListNode* cur = prev->next;

        for(int i = 0; i < right-left; i++)
        {
            ListNode* node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = node;
        }

        hh->next->next = cur;
        hh->next = prev;

        return dummyhead->next;
    }

};