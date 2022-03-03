/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
#include <string>
using namespace std;
class Solution
{
public:
    string toHex(int num)
    {
        string result;
        int curBit = 1;
        int a = -1;
        for (int i = 0; i < 32; i++)
        {
            cout << "bit " << i << ": " << (curBit & a) << endl;
            curBit <<= 1;
        }
        return result;
    }
};
// @lc code=end
