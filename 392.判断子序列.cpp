/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        bool result = true;
        int size = s.length();
        auto startPos = 0;
        for (int i = 0; i < size; i++)
        {
            auto c = s.substr(i, 1);
            auto pos = t.find(c, startPos);
            if (pos != string::npos)
            {
                startPos = pos + 1;
            }
            else
            {
                result = false;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
