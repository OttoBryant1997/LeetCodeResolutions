/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 * 摩尔投票法 (不同则消减)
 *
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // 1. do Vote
        int majority = nums[0];
        int count = 0;
        int arrSize = nums.size();
        for (int i = 0; i < arrSize; i++)
        {
            if (count == 0)
            {
                majority = nums[i];
                count = 1;
            }
            else
            {
                if (nums[i] == majority)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        // 2. do check
        // if (count > arrSize / 2)
        // {
        //     return majority;
        // }
        // else
        // {
        // }
        return majority;
    }
};
// @lc code=end
