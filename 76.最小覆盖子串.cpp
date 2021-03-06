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
        int window[128] = {0};       //窗口中字符的个数 含重复 仅记录有效字符 无效字符为0
        int target[128] = {0};       //目标的字符个数记录 含重复
        int targetCharTypeCount = 0; //目标内含有多少种字符 不重复
        int validTypeCharCount = 0;  //窗口中，有效的字符的种类记录 不重复
        int sufficientCharCount = 0; //窗口中，个数充足的字符种类数

        int minLen = 0;
        for (int i = 0; i < t.length(); i++)
        {
            if (target[t[i]] == 0)
                targetCharTypeCount++;
            target[t[i]]++;
        }

        for (int left = 0, right = 0; right < s.length(); right++)
        {
            //加一个右边界带来的影响
            if (target[s[right]] > 0)
            {                              //如果是有效字符
                if (window[s[right]] == 0) //第一次遇到有效字符 有效种类加一
                    validTypeCharCount++;
                window[s[right]]++;
                if (window[s[right]] == target[s[right]]) //该有效字符首次超过目标中该字符的个数
                    sufficientCharCount++;
            }
            if (validTypeCharCount == targetCharTypeCount &&
                sufficientCharCount == targetCharTypeCount)
            { //窗口中的字符种类齐全且 每个种类都最少字符数也达标
                while (target[s[left]] == 0 || window[s[left]] > target[s[left]])
                { //左边是无效字符或者左边字符在窗口中的个数很多，丢弃一个也能满足目标需要的个数
                    if (window[s[left]] > target[s[left]])
                    { //如果移动的是有效字符 需要更新数据
                        window[s[left]]--;
                    }
                    left++;
                }
                if (minLen == 0 || minLen > right - left + 1)
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
