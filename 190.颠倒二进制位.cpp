/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t curBit = 1;
        vector<int> bits;
        for (int i = 0; i < sizeof(n) * 8; i++)
        {
            auto curBitVal = n & curBit;
            curBit <<= 1;
            bits.push_back(curBitVal ? 1 : 0);
        }
        auto size = bits.size();
        uint32_t curPower = 1;
        uint32_t result = 0;
        for (int i = 0; i < size; i++)
        {
            result += bits[size - 1 - i] * curPower;
            curPower <<= 1;
            // cout << "result:" << result << "  bits[size - 1 - i]:" << bits[size - 1 - i] << endl;
        }
        return result;
    }
};
// @lc code=end
