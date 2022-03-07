/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *  滑动窗口
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        int left = -1;
        int right = 0;

        vector<int> dict(256, -1);
        while (right < s.length())
        {
            if (dict[s[right]] > left) //历史值大于当前值 说明是已经出现过了 把左端移动到历史值
                left = dict[s[right]];
            dict[s[right]] = right;
            result = max(right - left, result);
            right++;
        }
        return result;
    }
};
// @lc code=end

