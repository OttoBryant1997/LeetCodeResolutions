/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<bool> vals;
        vector<int> result;
        vals.resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            vals[nums[i] - 1] = true;
        }
        for (int i = 0; i < vals.size(); i++)
        {
            if (!vals[i])
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
// @lc code=end
