/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        df(root);
        return curMaxDepth;
    }

private:
    int curMaxDepth = 0;
    int curDepth = 0;
    bool df(TreeNode *node)
    {
        if (!node)
            return false;
        curDepth++;
        if (curMaxDepth < curDepth)
            curMaxDepth = curDepth;
        if (df(node->left))
        {
            curDepth--;
        }
        if (df(node->right))
        {
            curDepth--;
        }
        return true;
    }
};
// @lc code=end
