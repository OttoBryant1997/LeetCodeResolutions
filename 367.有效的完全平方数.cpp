// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem367.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 * 1+3+5+7+9+…+(2n-1)=n^2
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        double sum = 0;
        bool result = false;
        for (int i = 1; i <= num; i++)
        {
            sum += (2 * i - 1);
            if (sum == num)
            {
                result = true;
                break;
            }
            if (sum > num)
            {
                result = false;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
