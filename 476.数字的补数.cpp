/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        //找掩码
        unsigned mask = ~0;
        while (mask & num)
        {
            mask <<= 1;
        }
        //得出结果
        return ~mask ^ num;
    }
};
// @lc code=end
