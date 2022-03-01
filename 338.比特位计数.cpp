/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result;
        for (int i = 0; i <= n; i++)
        {
            result.push_back(getBitsNums(i));
        }
        return result;
    }

private:
    int getBitsNums(int x)
    {
        int curBit = 1;
        int result = 0;
        for (int i = 0; i < sizeof(x) * 8; i++)
        {
            result += x & curBit ? 1 : 0;
            if (i < 31)
                curBit <<= 1;
        }
        return result;
    }
};
// @lc code=end
