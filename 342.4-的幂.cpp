/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return n > 0 && (1 << 30) % n == 0 && n % 3 == 1;
    }

private:
    bool isOneBitOnOdd(int n)
    {
        return false;
    }
};
// @lc code=end
