/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

// @lc code=start
#include <set>
using namespace std;
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        set<int> factors;
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                factors.insert(i);
                factors.insert(num / i);
            }
        }
        factors.insert(1);
        int sum = 0;
        for (auto it : factors)
        {
            sum += it;
        }
        return sum == num;
    }
};
// @lc code=end
