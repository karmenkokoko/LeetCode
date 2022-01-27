#include <bits/stdc++.h>

using namespace std;
// 链表加和
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(0), next(nullptr) {}
    ListNode(int x, ListNode* Next): val(x), next(Next){}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // new 的话有一个dummy head 不好整
        ListNode *head = nullptr, *tail = nullptr;
        int cnt = 0;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val + cnt;
            if(!head)
            {
                head = tail = new ListNode(sum % 10);
            }
            else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            cnt = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            int sum = l1->val + cnt;
            tail->next = new ListNode(sum % 10);
            cnt = sum / 10;
            tail = tail->next;
            l1 = l1->next;
        }

        while(l2)
        {
            int sum = l2->val + cnt;
            tail->next = new ListNode(sum % 10);
            cnt = sum / 10;
            tail = tail->next;
            l2 = l2->next;
        }
        // 最后有一位进位
        if(cnt > 0)
            tail->next = new ListNode(cnt);
        return head;
    }
};