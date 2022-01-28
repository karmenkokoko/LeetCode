#include <bits/stdc++.h>

using namespace std;

// 归并链表

class Solution {
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        // 这里可以递归
        ListNode* l1 = head;
        ListNode* l2 = splitList(head);
        l1 = sortList(l1);
        l2 = sortList(l2);
        return mergesort(l1, l2);
    }

    ListNode* splitList(ListNode* head)
    {
        // 快慢指针分割链表
        // fast = head->next
        ListNode *slow = head, *fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* mergesort(ListNode* l1, ListNode* l2)
    {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        while(l1 && l2)
        {
            if(l1->val < l2->val) 
            {
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1 = l1->next;
            }
            else{
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2 = l2->next;
            }
        }
        while(l1)
        {
            temp->next = new ListNode(l1->val);
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2)
        {
            temp->next = new ListNode(l2->val);
            temp = temp->next;
            l2 = l2->next;
        }

        return res->next;

    }
};