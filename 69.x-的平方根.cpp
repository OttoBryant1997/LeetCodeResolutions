/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        double lastVal = 0;
        while (lastVal * lastVal <= x)
            lastVal++;
        return lastVal - 1;
    }
};
// @lc code=end