/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        double lo = 1;
        double hi = n;
        int result = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            auto gs = guess(mid);
            if (gs > 0)
            {
                lo = mid + 1;
            }
            else if (gs < 0)
            {
                hi = mid - 1;
            }
            else
            {
                result = mid;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
