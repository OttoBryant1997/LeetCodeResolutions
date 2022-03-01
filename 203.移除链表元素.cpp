/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *p = head;
        ListNode *result = nullptr;
        ListNode *worker = nullptr;
        while (p)
        {
            if (p->val != val)
            {
                if (!worker)
                {
                    result = worker = new ListNode(p->val);
                }
                else
                {
                    worker->next = new ListNode(p->val);
                    worker = worker->next;
                }
            }
            p = p->next;
        }
        return result;
    }
};
// @lc code=end
