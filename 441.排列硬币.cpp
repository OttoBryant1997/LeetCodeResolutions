// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem441.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int result = 0;
        for (double i = 1; i <= n; i++)
        {
            if ((i + 1) * i / 2 < n)
            {
                continue;
            }
            else if ((i + 1) * i / 2 > n)
            {
                result = i - 1;
                break;
            }
            else
            {
                result = i;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
