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
        for (auto word : words)
        {
            if (isSameLine(word))
            {
                result.push_back(word);
            }
        }
        return result;
    }

private:
    bool isSameLine(const string &str)
    {
        vector<int> index;
        for (int i = 0; i < str.length(); i++)
        {
            index.push_back(mpCharLines[str.substr(i, 1)]);
        }
        bool result = true;
        if (index.size() == 1)
        {
            result = true;
        }
        else
        {
            int lastLine = -1;
            for (int i = 0; i < index.size(); i++)
            {
                if (lastLine == -1)
                {
                    lastLine = index[0];
                }
                else
                {
                    if (lastLine != index[i])
                    {
                        result = false;
                        break;
                    }
                }
            }
        }
        return result;
    }
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
        {"M", 2},
        {"q", 0},
        {"w", 0},
        {"e", 0},
        {"r", 0},
        {"t", 0},
        {"y", 0},
        {"u", 0},
        {"i", 0},
        {"o", 0},
        {"p", 0},
        {"a", 1},
        {"s", 1},
        {"d", 1},
        {"f", 1},
        {"g", 1},
        {"h", 1},
        {"j", 1},
        {"k", 1},
        {"l", 1},
        {"z", 2},
        {"x", 2},
        {"c", 2},
        {"v", 2},
        {"b", 2},
        {"n", 2},
        {"m", 2}};
};
// @lc code=end
