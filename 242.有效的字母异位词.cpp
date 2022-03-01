/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<string, int> charNums;
        if (s.length() != t.length())
            return false;
        bool result = true;
        for (int i = 0; i < s.length(); i++)
        {
            auto c = s.substr(i, 1);
            if (charNums[c] == 0)
            {
                charNums[c] = 1;
            }
            else
            {
                charNums[c] += 1;
            }
        }
        for (int i = 0; i < t.length(); i++)
        {
            auto c = t.substr(i, 1);
            if (charNums[c] == 0)
            {
                result = false;
                break;
            }
            else
            {
                charNums[c] -= 1;
            }
        }
        return result;
    }
};
// @lc code=end
