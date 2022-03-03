/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        int result = -1;
        map<string, int> mapCharCount;
        int size = s.length();
        for (int i = 0; i < size; i++)
        {
            auto c = s.substr(i, 1);
            if (mapCharCount.find(c) != mapCharCount.end())
            {
                mapCharCount[c]++;
            }
            else
            {
                mapCharCount[c] = 1;
            }
        }
        for (auto i = 0; i < size; i++)
        {
            if (mapCharCount[s.substr(i, 1)] == 1)
            {
                result = i;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
