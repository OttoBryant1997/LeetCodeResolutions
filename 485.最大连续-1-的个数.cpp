/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int result = 0;
        int continueOneNum = 0;
        bool isPreOne = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                continueOneNum++;
                isPreOne = true;
            }
            else
            {
                if (isPreOne)
                {
                    result = result > continueOneNum ? result : continueOneNum;
                }
                isPreOne = false;
                continueOneNum = 0;
            }
        }
        if (isPreOne)
        {
            result = result > continueOneNum ? result : continueOneNum;
        }
        return result;
    }
};
// @lc code=end
