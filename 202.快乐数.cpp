/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * 不快乐数会陷入循环 快慢指针法
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        int fast = n;
        int slow = n;
        bool result = false;
        while (true)
        {
            fast = getPowerSum(SplitNumbers(getPowerSum(SplitNumbers(fast))));
            slow = getPowerSum(SplitNumbers(slow));
            if (fast == 1)
            {
                result = true;
                break;
            }
            if (fast == slow)
            {
                result = false;
                break;
            }
        }
        return result;
    }

private:
    vector<int> SplitNumbers(int n)
    {
        vector<int> result;
        while (n >= 10)
        {
            result.push_back(n % 10);
            n /= 10;
        }
        result.push_back(n % 10);
        return result;
    }
    int getPowerSum(vector<int> vals)
    {
        int result = 0;
        for (auto val : vals)
        {
            result += (val * val);
        }
        return result;
    }
};
// @lc code=end
