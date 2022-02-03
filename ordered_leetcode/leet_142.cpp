#include <bits/stdc++.h>

using namespace std;
// 快慢指针判环

// fast = 2s;
// fast = s + nb;
// slow = nb;
// 快指针为1, 2式
// 相遇时，慢指针走了n个环
// 因此，只要再走a步， fast=head， fast和slow相等即是相交点
// 因为环开始处的步数是a+nb
class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public: 
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while(true)
        {
            if(!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                break;
            }
        }
        
        if(fast == nullptr)
            return nullptr;
        else{
            fast = head;
            while(slow != fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        
    }
};