/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        mTargetSum = targetSum;
        if (!root)
            return false;
        df(root);
        return mHasTargetSun;
    }

private:
    bool mHasTargetSun = false;
    int mTargetSum = 0;
    int mCurSum = 0;

private:
    int df(TreeNode *node)
    {
        if (!node)
            return 0;
        mCurSum += node->val;
        if (!node->left && !node->right && !mHasTargetSun)
        {
            mHasTargetSun = mCurSum == mTargetSum;
        }
        else
        {
            mCurSum -= df(node->left);
            mCurSum -= df(node->right);
        }
        return node->val;
    }
};
// @lc code=end
