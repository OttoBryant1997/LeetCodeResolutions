// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem125.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        bool result = true;
        vector<char> data;
        int strLen = s.length();
        auto strData = s.data();
        for (int i = 0; i < strLen; i++)
        {
            if ((strData[i] >= 'a' && strData[i] <= 'z') || (strData[i] >= 'A' && strData[i] <= 'Z') || (strData[i] >= '0' && strData[i] <= '9'))
            {
                data.push_back(tolower(strData[i]));
            }
        }

        int dataLen = data.size();
        if (dataLen == 0)
            return result;
        for (int i = 0; i <= dataLen / 2; i++)
        {
            if (data[i] != data[dataLen - i - 1])
            {
                result = false;
                break;
            }
        }
        return result;
    }
};
// @lc code=end
