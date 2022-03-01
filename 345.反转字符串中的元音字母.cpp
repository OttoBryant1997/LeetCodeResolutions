// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem345.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<int> volIndex;
        auto sL = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            if (isVol(s.substr(i, 1)))
            {
                volIndex.push_back(i);
            }
        }
        if (volIndex.size() == 0 || volIndex.size() == 1)
            return s;
        string result;
        int j = 0;
        cout << "volIndex.size:" << volIndex.size() << endl;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == volIndex[j])
            {
                result += s.substr(volIndex[volIndex.size() - 1 - j], 1);
                if (j < volIndex.size() - 1)
                    j++;
            }
            else
            {
                result += s.substr(i, 1);
            }
        }
        return result;
    }

private:
    bool isVol(const string &s)
    {
        return s == "a" || s == "e" || s == "i" || s == "o" || s == "u" || s == "A" || s == "E" || s == "I" || s == "O" || s == "U";
    }
};
// @lc code=end
