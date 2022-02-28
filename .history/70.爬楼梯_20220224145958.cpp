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
 * n=4 f(n)=f(2)+f(3)
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp;
        dp.resize(n + 1);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
        }
    }
};
// @lc code=end
