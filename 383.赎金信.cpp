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
        map<string, int> magCNumbers;
        auto rL = ransomNote.length();
        auto mL = magazine.length();
        for (int i = 0; i < mL; ++i)
        {
            auto c = magazine.substr(i, 1);
            if (magCNumbers.find(c) == magCNumbers.end())
            {
                magCNumbers.insert({c, 1});
            }
            else
            {
                magCNumbers[c] += 1;
            }
        }

        for (int i = 0; i < rL; i++)
        {
            auto c = ransomNote.substr(i, 1);
            if (magCNumbers.find(c) != magCNumbers.end())
            {
                magCNumbers[c]--;
                if (magCNumbers[c] == 0)
                {
                    magCNumbers.erase(c);
                }
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
