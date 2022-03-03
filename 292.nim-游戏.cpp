// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem292.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 * 每个人可以拿1-k个石头，共N个石头
 * 保证先手者可以胜利 则 倒数第二手时必须有 k + 1个石头
 *
 */

// @lc code=start
class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};
// @lc code=end
