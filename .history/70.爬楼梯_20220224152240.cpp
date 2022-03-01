// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 * 序列的排列组合方式默认用动规
 * 现在考察 f(n)与f(n-1)的关系
 * 直接总结较难的话可以采用归纳法
 * n=0 f(n)=0
 * n=1 f(n)=1
 * n=2 f(n)=2
 * n=3 f(n)=3
 * n=4 f(4)=f(2)+f(3)
 * 不好总结，考虑最后一步 容易得出f(n)=f(n-1)+f(n-2)
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
int[46] g_dp;
class Solution
{
public:
    int climbStairs(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i <= 3)
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
