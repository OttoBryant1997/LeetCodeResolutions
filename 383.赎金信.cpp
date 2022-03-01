/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        bool result = true;
        map<string, int> ransomNumbers;
        auto rL = ransomNote.length();
        auto mL = ransomNote.length();
        for (int i = 0; i < rL; ++i)
        {
            auto c = ransomNote.substr(i, 1);
            if (ransomNumbers.find(c) == ransomNumbers.end())
            {
                ransomNumbers.insert({c, 1});
            }
            else
            {
                ransomNumbers[c] += 1;
            }
        }

        for (int i = 0; i < mL; i++)
        {
            auto c = ransomNote.substr(i, 1);
            if (ransomNumbers.find(c) != ransomNumbers.end() && ransomNumbers[c] == 1)
            {
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
