// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem409.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        auto size = s.length();
        map<string, int> charCount;
        for (int i = 0; i < size; i++)
        {
            auto c = s.substr(i, 1);
            if (charCount.find(c) == charCount.end())
            {
                charCount[c] = 1;
            }
            else
            {
                charCount[c]++;
            }
        }
        int result = 0;
        for (auto it : charCount)
        {
            cout << "char:" << it.first
                 << " num:" << it.second << endl;
            auto count = it.second;
            result += count / 2 * 2;
            if (count % 2 == 1 && result % 2 == 0)
            {
                result++;
            }
        }

        return result;
    }
};
// @lc code=end
