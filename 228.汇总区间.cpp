/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        if (nums.size() == 0)
            return result;
        int start = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                if (start == nums[i - 1])
                {
                    result.push_back(to_string(start));
                }
                else
                {
                    auto s = to_string(start) + "->" + to_string(nums[i - 1]);
                    result.push_back(s);
                }
                start = nums[i];
            }
        }
        auto lastEle = nums[nums.size() - 1];
        if (start == lastEle)
        {
            result.push_back(to_string(start));
        }
        else
        {
            auto s = to_string(start) + "->" + to_string(lastEle);
            result.push_back(s);
        }
        return result;
    }
};
// @lc code=end
