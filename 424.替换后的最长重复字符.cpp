/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 * 动态滑动窗口:窗口中的元素总数 = k + 数量较多的元素的个数
 * 且 k = 其它元素的个数
 * 迭代最值这个是一个弱点
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int result = 0;
        int dict[125] = {0};
        int sLen = s.length();
        int maxCount = 0; //当前窗口中出现的最多元素出现的次数
        for (int left = 0, right = 0; right < sLen; right++)
        {
            dict[s[right]]++;
            maxCount = max(maxCount, dict[s[right]]);
            while (right - left + 1 - maxCount > k) //不满足条件才缩小
            {
                dict[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
