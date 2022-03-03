/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 * (input) ^ (0...n)
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int result = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
            result ^= i;
        }
        return result;
    }
};
// @lc code=end
