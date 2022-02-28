/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<string, string> charMapAToB;
        map<string, string> charMapBToA;
        int sizeA = s.size();
        int sizeB = t.size();
        bool result = true;
        if (sizeA != sizeB)
            return false;
        for (int i = 0; i < sizeA; i++)
        {

            auto charA = s.substr(i, 1);
            auto charB = t.substr(i, 1);
            auto itAToB = charMapAToB.find(charA);
            auto itBToA = charMapBToA.find(charB);
            if (itAToB == charMapAToB.end() && itBToA == charMapBToA.end())
            {
                charMapAToB.insert({charA, charB});
                charMapBToA.insert({charB, charA});
            }
            else
            {
                if (itAToB != charMapAToB.end() && (*itAToB).second != charB)
                {
                    result = false;
                    break;
                }
                if (itBToA != charMapBToA.end() && (*itBToA).second != charA)
                {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end
