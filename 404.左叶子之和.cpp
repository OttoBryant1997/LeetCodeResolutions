/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        df(root->left, root->right);
        return m_curSum;
    }

private:
    int m_curSum = 0;
    void df(TreeNode *left, TreeNode *right)
    {
        if (left)
        {
            if (!left->left && !left->right)
            {
                m_curSum += left->val;
            }
            df(left->left, left->right);
        }
        if (right)
        {
            df(right->left, right->right);
        }
    }
};
// @lc code=end
