/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int result = 0;
        int dist = x ^ y;
        int curBit = 1;
        for (int i = 0; i < 31; i++)
        {
            if (curBit & dist)
            {
                result++;
            }
            curBit <<= 1;
        }
        return result;
    }
};
// @lc code=end
