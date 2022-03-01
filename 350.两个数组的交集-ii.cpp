/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start

#include <map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> s1;
        map<int, int> s2;
        for (auto it : nums1)
        {
            if (s1.find(it) == s1.end())
            {
                s1.insert({it, 1});
            }
            else
            {
                s1[it] += 1;
            }
        }
        for (auto it : nums2)
        {
            if (s1.find(it) == s2.end())
            {
                s2.insert({it, 1});
            }
            else
            {
                s2[it] += 1;
            }
        }
        vector<int> result;
        for (auto it : s1)
        {
            auto s1Val = it.first;
            auto s1Count = it.second;
            if (s2.find(s1Val) != s2.end())
            {
                auto small = s1Count < s2[s1Val] ? s1Count : s2[s1Val];
                for (int i = 0; i < small; i++)
                {
                    result.push_back(s1Val);
                }
            }
        }
        return result;
    }
};
// @lc code=end
