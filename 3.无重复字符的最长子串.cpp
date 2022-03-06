// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem3.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int curLen = 0;
        int longestLen = 0;
        int left = 0;
        int right = 0;
        while (right < s.length())
        {
            // 更新当前结果
            curLen = right - left + 1;
            // 什么时候移动左指针 ？ 有重复
            while (hasDuplicate(left, right, s))
            {
                left++;
            }
            right++;
        }
        return result;
    }

private:
    bool hasDuplicate(int l, int r, string s)
    {
        set<string> visited;
        bool result = false;
        for (int i = 0; i < r - l; i++)
        {
            if (visited.find(s.substr(l + i)) == visited.end())
            {
                visited.insert(s.substr(l + i));
            }
            else
            {
                result = true;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
