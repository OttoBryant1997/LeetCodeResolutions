/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 * result = sum(i-min)
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int minVal = nums[0];
        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            minVal = minVal < nums[i] ? minVal : nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            result += nums[i] - minVal;
        }
        return result;
    }
};
// @lc code=end
