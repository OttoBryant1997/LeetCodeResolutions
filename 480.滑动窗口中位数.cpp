/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> result;
        if (k == 0)
            return result;
        deque<int> window;
        int numsSize = nums.size();
        for (int left = 0, int right = 0; right < numsSize; right++)
        {
            
        }
        return result;
    }
};
// @lc code=end
