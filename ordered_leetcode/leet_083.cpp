#include <bits/stdc++.h>

using namespace std;

// 删除链表中的重复元素，留一个
// 用哈希表存次数 可以用于未排序的链表


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        unordered_map<int, int> map;
        ListNode* cur = head;
        ListNode* prev = nullptr; // 也要用prev来存cur这个node， 不然会动。

        while(cur)
        {
            if(map[cur->val] > 0)
            {
                // 遍历表来找第一个不重复的元素
                prev->next = cur->next;
            }
            else{
                map[cur->val]++;
                prev = cur;

            }
            cur = cur->next;
        }
        return head;
    }
};