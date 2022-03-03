// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem459.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string str = s + s;
        str = str.substr(1, str.size() - 2);
        if (str.find(s) == string::npos)
            return false;
        return true;
    }
};
// @lc code=end
