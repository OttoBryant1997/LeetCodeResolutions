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
 * 对于字符串，宁愿做reverse也不要做头插
 */

// @lc code=start
#line 16
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    inline string licenseKeyFormatting(string s, int k)
    {
        string ans;
        size_t cnt{};
        for_each(s.rbegin(), s.rend(), [&](auto &ch)
                 {
                if (isalnum(ch)) {
                    if (cnt++ == k) {
                        ans.push_back('-');
                        cnt = 1;
                    }
                    ans.push_back(toupper(ch));
                } });
        reverse(ans.begin(), ans.end());
        return ans;
        // replace_all(s, "-", "");
        // int size = s.length();
        // if (size == 0)
        //     return "";
        // for (int i = 0; i < size; i++)
        // {
        //     s[i] = toupper(s[i]);
        // }
        // string result;
        // string sep = "-";
        // for (int i = 0; i < size; i++)
        // {
        //     if ((i + 1) % k == 0 && i != size - 1)
        //     {
        //         result = sep + s[size - 1 - i] + result;
        //     }
        //     else
        //     {
        //         result = s[size - 1 - i] + result;
        //     }
        // }
        // return result;
    }
};
// @lc code=end
