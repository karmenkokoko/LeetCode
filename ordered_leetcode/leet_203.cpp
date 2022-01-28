#include <bits/stdc++.h>

using namespace std;
// 移除元素
// 可能有空链表的情况，用dummyhead来解决

// 迭代cur->next

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyhead = new ListNode(0, head);
        ListNode *cur = dummyhead;
        while(cur->next)
        {
            if(cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        return dummyhead->next;
    }
};