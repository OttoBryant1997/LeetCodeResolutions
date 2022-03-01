/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int len = s.size();
        cout << "len =" << len << endl;
        int halfLen = len / 2;
        for (int i = 0; i < halfLen; i++)
        {
            auto tmp = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = tmp;
        }
    }
};
// @lc code=end
