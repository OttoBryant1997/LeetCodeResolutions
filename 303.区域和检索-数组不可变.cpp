/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <vector>
class NumArray
{
public:
	NumArray(vector<int> &nums)
	{
		m_nums = nums;
	}

	int sumRange(int left, int right)
	{
		int result = 0;
		for (int i = left; i <= right; i++)
		{
			result += m_nums[i];
		}
		return result;
	}

private:
	vector<int> m_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
