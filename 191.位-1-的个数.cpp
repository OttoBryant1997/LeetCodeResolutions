/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        uint32_t curPower = 1;
        for (int i = 0; i < sizeof(n) * 8; i++)
        {
            auto curBit = curPower & n;
            if (curBit)
                result++;
            curPower <<= 1;
        }
        return result;
    }
};
// @lc code=end
