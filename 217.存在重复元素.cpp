/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <set>
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> eles;
        bool result = false;
        for (auto val : nums)
        {
            if (eles.find(val) != eles.end())
            {
                result = true;
                break;
            }
            else
            {
                eles.insert(val);
            }
        }
        return result;
    }
};
// @lc code=end
