/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> result;
        map<string, int> mpCharLines = {
            {"Q", 0},
            {"W", 0},
            {"E", 0},
            {"R", 0},
            {"T", 0},
            {"Y", 0},
            {"U", 0},
            {"I", 0},
            {"O", 0},
            {"P", 0},
            {"A", 1},
            {"S", 1},
            {"D", 1},
            {"F", 1},
            {"G", 1},
            {"H", 1},
            {"J", 1},
            {"K", 1},
            {"L", 1},
            {"Z", 2},
            {"X", 2},
            {"C", 2},
            {"V", 2},
            {"B", 2},
            {"N", 2},
            {"M", 2}};

        return result;
    }
};
// @lc code=end
