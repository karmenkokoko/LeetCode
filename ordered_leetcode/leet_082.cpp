#include <bits/stdc++.h>

using namespace std;

// 删除链表中的重复元素，不留
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
        ListNode* dummyhead = new ListNode(0, head);
        ListNode* prev = dummyhead;
        ListNode* curNode = head;
        unordered_map<int, int> map;
        while(head){
            map[head->val]++;
            head = head->next;
        }
        while(curNode){
            if(map[curNode->val] > 1){
                prev->next = curNode->next;
            }
            else{
                prev = curNode;
            }
            curNode = curNode->next;
        }
        return dummyhead->next;

    }
};