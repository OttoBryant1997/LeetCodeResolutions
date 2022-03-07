/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 * 固定滑动窗口+单调队列
 */

// @lc code=start
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        deque<int> window;
        for (int i = 0, n = nums.size(); i < n; i++)
        {
            while (!window.empty() && window.front() <= i - k)
                window.pop_front();
            while (!window.empty() && nums[window.back()] <= nums[i])
                window.pop_back();
            window.push_back(i);
            if (i >= k - 1)
                result.push_back(nums[window.front()]);
        }
        return result;
    }
};
// @lc code=end
