/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 * p <= root && q >= root 则root为最近公共祖先
 * p < root && q << root 往左子树遍历
 * p > root && q > root 往右字数遍历
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || !p || !q)
            return nullptr;
        TreeNode *result = nullptr;
        if (p->val < root->val && q->val < root->val)
        {
            result = lowestCommonAncestor(root->left, p, q);
            if (result)
                return result;
        }

        else if (p->val > root->val && q->val > root->val)
        {
            result = lowestCommonAncestor(root->right, p, q);
            if (result)
                return result;
        }
        else
        {
            result = root;
            return result;
        }
        return result;
    }
};
// @lc code=end
