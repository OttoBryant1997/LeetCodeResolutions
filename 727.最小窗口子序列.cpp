/*
 * @lc app=leetcode.cn id=727 lang=cpp
 *
 * [727] 最小窗口子序列
 *
 * 有序的查找 必须是逐个比 然后再缩小窗口
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length(), m = t.length(), p = 0, q = 0, left = 0, right = 0, minlen = INT_MAX;
        string ans = "";
        while (p < n)
        {
            if (s[p] == t[q])
                q++;
            if (q == m)
            {
                right = p;
                q--;
                while (q >= 0)
                {
                    if (s[p] == t[q])
                        q--;
                    p--;
                }
                left = ++p;
                q = 0;
                if ((right - left + 1) < minlen)
                {
                    ans = s.substr(left, right - left + 1);
                    minlen = right - left + 1;
                }
            }
            p++;
        }
        return ans;
    }
};
// @lc code=end
