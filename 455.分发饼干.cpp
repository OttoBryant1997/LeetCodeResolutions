/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // g 胃口 s 饼干大小
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        int gIdx = 0;
        int sIdx = 0;
        while (gIdx < g.size() && sIdx < s.size())
        {
            if (g[gIdx] <= s[sIdx])
            {
                result++;
                gIdx++;
            }
            sIdx++;
        }
        return result;
    }
};
// @lc code=end
