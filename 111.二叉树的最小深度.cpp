/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 * 判断叶子节点的深度即可
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
    int minDepth(TreeNode *root)
    {
        df(root);
        return curMinLeafDepth;
    }

private:
    int curDepth = 0;
    int curMinLeafDepth = 0;
    bool df(TreeNode *node)
    {
        if (!node)
            return false;
        curDepth++;
        if (!node->right && !node->left)
            if (curMinLeafDepth == 0)
                curMinLeafDepth = curDepth;
            else
                curMinLeafDepth = curDepth < curMinLeafDepth ? curDepth : curMinLeafDepth;
        else
        {
            if (df(node->left))
                curDepth--;
            if (df(node->right))
                curDepth--;
        }
        return true;
    }
};
// @lc code=end
