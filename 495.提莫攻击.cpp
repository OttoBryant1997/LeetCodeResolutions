/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int size = timeSeries.size();
        int start = 0;
        int end = 0;
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                start = timeSeries[i];
            }
            else
            {
                if (timeSeries[i] > end)
                {
                    total += (end - start + 1);
                    start = timeSeries[i];
                }
            }
            end = timeSeries[i] + duration - 1;
            if (i == size - 1)
            {
                total += (end - start + 1);
            }
        }
        return total;
    }
};
// @lc code=end
