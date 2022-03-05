/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * 暂时不会 弱项
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;
class Solution
{
public:
    TreeNode *dfs(vector<int> &nums, int p_left, int p_right)
    {
        if (p_left >= p_right)
            return NULL;
        int mid = (p_right + p_left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, p_left, mid);
        root->right = dfs(nums, mid + 1, p_right);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int len = nums.size();
        return dfs(nums, 0, len);
    }
};
// @lc code=end
