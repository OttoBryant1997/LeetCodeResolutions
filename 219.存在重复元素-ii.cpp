/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <map>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                cout << "i:" << i << "  idx:" << map[nums[i]] << endl;
                if (i - map[nums[i]] <= k)
                    return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
