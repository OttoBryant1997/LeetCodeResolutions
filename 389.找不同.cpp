/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    char findTheDifference(string s, string t)
    {

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
        char result;
        size = t.length();
        for (int i = 0; i < size; i++)
        {
            auto c = t.substr(i, 1);
            if (mapCharCount.find(c) == mapCharCount.end())
            {
                result = *c.data();
                break;
            }
            else
            {
                mapCharCount[c]--;
                if (mapCharCount[c] == 0)
                    mapCharCount.erase(c);
            }
        }
        return result;
    }
};
// @lc code=end
