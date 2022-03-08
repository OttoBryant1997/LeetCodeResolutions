/*
 * @lc app=leetcode.cn id=340 lang=cpp
 *
 * [340] 至多包含 K 个不同字符的最长子串
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int result = 0;
        int window[128] = {0};
        int diffCount = 0;
        for (int left = 0, right = 0; right < s.length(); right++)
        {
            if (window[s[right]] == 0)
                diffCount++;
            window[s[right]]++;
            while (diffCount > k)
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
