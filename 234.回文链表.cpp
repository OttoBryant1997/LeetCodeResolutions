/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        vector<int> vals;
        while (p)
        {
            vals.push_back(p->val);
            p = p->next;
        }
        if (vals.size() == 1)
            return true;
        bool result = true;
        int size = vals.size();
        for (int i = 0; i < size / 2; i++)
        {
            if (vals[i] != vals[size - 1 - i])
            {
                result = false;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
