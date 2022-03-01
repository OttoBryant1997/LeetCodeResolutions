/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int n)
    {
        if(n==0) return false;
        if (n == 1)
            return true;
        while (true)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }

            else if (n % 3 == 0)
            {
                n /= 3;
            }
            else if (n % 5 == 0)
            {
                n /= 5;
            }
            else
                break;
        }
        bool result = false;
        if (n == 1)
            result = true;
        else
            result = false;
        return result;
    }
};
// @lc code=end
