/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int lo = 1;
        int hi = n;

        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return hi;
    }
};
// @lc code=end
