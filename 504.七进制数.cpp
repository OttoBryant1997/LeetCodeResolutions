/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        string ret;
        int flag = 0;
        if (num < 0)
            flag = 1;
        num = abs(num);
        while (num != 0)
        {
            ret.push_back((num % 7) + '0');
            num /= 7;
        }
        reverse(ret.begin(), ret.end());
        if (flag == 1)
        {
            ret.insert(ret.begin(), '-');
        }
        return ret;
    }
};
// @lc code=end
