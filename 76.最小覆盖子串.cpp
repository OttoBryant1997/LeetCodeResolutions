// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 * 滑动窗口
 * 基于计数的方式进行处理
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        string result;
        if (s.empty() || t.empty())
            return result;
        int targetCharNums[125] = {0}; //目标中各字母的个数
        int windowCharNums[125] = {0}; //窗口中各字母的个数
        int validCharNums = 0;         //窗口中有效字母的个数
        int minLen = INT_MAX;
        auto sData = s.c_str();
        auto tData = t.c_str();
        int tLen = t.length();
        int sLen = s.length();
        for (int i = 0; i < t.length(); i++)
        {
            targetCharNums[t[i]]++;
        }
        for (int left = 0, right = 0; right < sLen; right++)
        {
            auto c = sData[right];
            if (targetCharNums[c] > 0)
            {
                windowCharNums[c]++;
                if (windowCharNums[c] <= targetCharNums[c])
                    validCharNums++;
            }
            if (validCharNums >= tLen)
            {
                while (targetCharNums[sData[left]] == 0 || windowCharNums[s[left]] > targetCharNums[sData[left]])
                {
                    // if (targetCharNums.find(s[left]) != targetCharNums.end())
                    windowCharNums[sData[left]]--;
                    left++;
                }
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    result = s.substr(left, minLen);
                }
            }
        }
        return result;
    }
};
// @lc code=end
