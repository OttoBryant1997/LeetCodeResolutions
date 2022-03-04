/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int maxdepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(maxdepth(root->left), maxdepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        int gap = abs(maxdepth(root->left) - maxdepth(root->right));
        return gap <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end
