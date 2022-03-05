/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 * 越界，考虑序列的拼接
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> idxStack;
        vector<int> result;

        int arrSize = nums.size();
        int loopSize = arrSize * 2;
        result.resize(arrSize);
        fill(result.begin(), result.end(), -1);
        for (int i = 0; i < loopSize; i++)
        {
            auto element = nums[i % arrSize];
            while (!idxStack.empty() && element > nums[idxStack.top()])
            {
                result[idxStack.top() % arrSize] = element;
                idxStack.pop();
            }
            idxStack.push(i % arrSize);
        }
        return result;
    }
};
// @lc code=end
