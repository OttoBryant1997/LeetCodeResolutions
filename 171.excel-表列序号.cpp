/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        map<string, int> charToVal = {
            {"A", 1},
            {"B", 2},
            {"C", 3},
            {"D", 4},
            {"E", 5},
            {"F", 6},
            {"G", 7},
            {"H", 8},
            {"I", 9},
            {"J", 10},
            {"K", 11},
            {"L", 12},
            {"M", 13},
            {"N", 14},
            {"O", 15},
            {"P", 16},
            {"Q", 17},
            {"R", 18},
            {"S", 19},
            {"T", 20},
            {"U", 21},
            {"V", 22},
            {"W", 23},
            {"X", 24},
            {"Y", 25},
            {"Z", 26},
        };
        int size = columnTitle.size();
        int result = 0;
        int power = 1;
        for (int i = 0; i < size; i++)
        {
            result += charToVal[columnTitle.substr(size - i - 1, 1)] * power;
            if (i != size - 1)
                power *= 26;
        }
        return result;
    }
};
// @lc code=end
