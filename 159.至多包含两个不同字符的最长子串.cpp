/*
 * @lc app=leetcode.cn id=159 lang=cpp
 *
 * [159] 至多包含两个不同字符的最长子串
 * 滑动窗口 求最长
 *
 *
 */

// @lc code=start
#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        // 右指针影响： 当前含有的字母种类数 当前右指针字母的个数
        // 左指针影响: 当前含有的字母种类数 当前右指针字母的个数
        // 判断条件
        int diffCount = 0;
        int window[128] = {0};
        int result = 0;
        for (int left = 0, right = 0; right < s.length(); right++)
        {
            if (window[s[right]] == 0)
                diffCount++;
            window[s[right]]++;
            while (diffCount > 2)
            {
                window[s[left]]--;
                if (window[s[left]] == 0)
                    diffCount--;
                left++;
            }
            if (result == 0 || result < right - left + 1)
            {
                result = right - left + 1;
            }
        }
        return result;
    }
};
// @lc code=end
