// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem482.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */

// @lc code=start
#line 16
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        int size = s.length();
        vector<string> tmp;
        auto data = s.c_str();
        string result;
        int validIdx = 0;
        for (int i = 0; i < size; i++)
        {
            cout << "cur index:" << size - 1 - i << endl;
            char curVal = data[size - 1 - i];
            cout << "get curVal:" << curVal << endl;
            if (curVal != '-')
            {
                validIdx++;

                if (curVal >= 'a' && curVal <= 'z')
                {
                    curVal = 'A' + (curVal - 'a');
                }

                if ((validIdx + 1) % k == 0 && i != size - 1)
                {
                    result = "-" + curVal + result;
                }
                else
                {
                    result = curVal + result;
                }
            }
        }
        return result;
    }
};
// @lc code=end
