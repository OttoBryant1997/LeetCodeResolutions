/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int curMinPrice = prices[0];
        int curMaxProfit = 0;
        int arrSize = prices.size();
        for (int i = 0; i < arrSize; i++)
        {
            curMinPrice = min(curMinPrice, prices[i]);
            curMaxProfit = max(curMaxProfit, prices[i] - curMinPrice);
        }
        int result = 0;
        if (curMaxProfit > 0)
        {
            result = curMaxProfit;
        }
        return result;
    }
};
// @lc code=end
