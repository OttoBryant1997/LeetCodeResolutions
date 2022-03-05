/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 *
 * 此问题属于NGE问题的变种 采用单调递减栈完成
 */

// @lc code=start
#include <vector>
#include <stack>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    { // nums1 是 nums2的子集
        vector<int> result;
#pragma region 对 nums2 做NGE处理 ，并将结果存入映射
        int size2 = nums2.size();
        stack<pair<int, int>> decStack; // first: VALUE second:index
        map<int, int> lookup;           // key:value in arr,val:NGE
        for (int i = 0; i < size2; i++)
        {
            while (true)
            {
                // push
                if (decStack.size() == 0 || nums2[i] < decStack.top().first)
                {
                    decStack.push({nums2[i], i});
                    break;
                }
                // pop,then compare
                else
                {
                    lookup.insert({decStack.top().first, nums2[i]});
                    decStack.pop();
                }
            }
        }
#pragma endregion
#pragma region 遍历nums1查lookup表 获取结果
        int size1 = nums1.size();
        for (auto i = 0; i < size1; i++)
        {
            if (lookup.find(nums1[i]) == lookup.end())
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(lookup[nums1[i]]);
            }
        }
#pragma endregion
        return result;
    }
};
// @lc code=end
