/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 * s = abc = a*100+b*10+c,s1 = a+b+c
 * s-s1 = 99*a+9*b
 * (s-s1)%9=(11*9*a+9*b)%9=9*(11*a+b)*9%9=0
 * s%9=s1
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        return (num - 1) % 9 + 1;
    }
};
// @lc code=end
