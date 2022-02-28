/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
    void deleteNode(ListNode *node)
    {
        if (!node)
            return;
        ListNode *p1 = node;
        ListNode *p2 = node->next;
        while (p2)
        {
            p1->val = p2->val;
            if (!p2->next)
            {
                p1->next = nullptr;
                break;
            }
            else
            {
                p1 = p2;
                p2 = p2->next;
            }
        }
    }
};
// @lc code=end
