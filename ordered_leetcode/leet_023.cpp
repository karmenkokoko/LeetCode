#include <bits/stdc++.h>

using namespace std;
// 23. 合并K个升序链表
// 给你一个链表数组，每个链表都已经按升序排列。

// 请你将所有链表合并到一个升序链表中，返回合并后的链表。


// 归并的思想，vector<int> [0, 1, 2, 3, 4, 5, 6]
// 对List的数组进行分割合并
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
    ListNode* mergetwolist(ListNode* l1, ListNode* l2)
    {
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        ListNode *head = new ListNode();
        ListNode *temp = head, *ptr1 = l1, *ptr2 = l2;
        while(ptr1 && ptr2)
        {
            if(ptr1->val <= ptr2->val)
            {
                temp->next = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            }
            else{
                temp->next = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }
            temp = temp->next;
        }
        if(ptr1 || ptr2)
            temp->next = ptr1 ? ptr1 : ptr2;
        return head->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        // 归并完成， 返回List[l]
        if(l == r)
            return lists[l];
        if(l > r)
            return nullptr;
        int mid = (l + r) >> 1;
        return mergetwolist(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};