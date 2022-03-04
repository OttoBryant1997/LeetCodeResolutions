/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s;
        set<int> res;
        vector<int> result;
        for (auto it : nums1)
        {
            s.insert(it);
        }
        for (auto it : nums2)
        {
            if (s.find(it) != s.end() && res.find(it) == res.end())
            {
                result.push_back(it);
                res.insert(it);
            }
        }
        return result;
    }
};
// @lc code=end
