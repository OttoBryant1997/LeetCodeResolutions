/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
int dp[31];
class Solution
{
public:
    int fib(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i <= 1)
            {
                dp[i] = i;
            }
            else
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        return dp[n];
    }
};
// @lc code=end
