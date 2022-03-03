/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 * 两个链表长度加起来的长度和 A+B = B+A
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB)
        {
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        return pA;
    }
};
// @lc code=end
