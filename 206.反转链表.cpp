/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *p1 = nullptr;
        ListNode *p2 = head;
        while (p2)
        {
            ListNode *tmp = p2->next;
            p2->next = p1;

            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
};
// @lc code=end
