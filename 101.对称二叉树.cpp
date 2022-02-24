/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 * 先比较指针 后比对称节点和值
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;
        return compare(root->left, root->right);
    }

private:
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (!left)
            return !right;
        if (!right)
            return false;
        return compare(left->left, right->right) && compare(left->right, right->left) && left->val == right->val;
    }
};
// @lc code=end
