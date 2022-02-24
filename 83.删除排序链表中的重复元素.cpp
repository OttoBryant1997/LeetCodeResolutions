/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
#include <set>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head;
        set<int> values;
        vector<int> tmp;
        while (p)
        {
            if (values.find(p->val) == values.end())
            {
                values.insert(p->val);
                tmp.push_back(p->val);
            }
            p = p->next;
        }
        ListNode *result = nullptr;
        ListNode *resultTail = nullptr;
        for (const auto &val : tmp)
        {
            auto p = new ListNode(val);
            if (!result)
            {
                result = p;
            }
            else
            {
                resultTail->next = p;
            }
            resultTail = p;
        }
        return result;
    }
};
// @lc code=end
