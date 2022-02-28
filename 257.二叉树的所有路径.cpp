/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return mResult;
        df(root, {});
        for (auto str : mVals)
        {
            cout << endl;
            string res = "";
            for (int i = 0; i < res.length(); i++)
            {
                cout << c << "--";
                res +
            }
            cout << endl;
        }

        return mResult;
    }

private:
    void df(TreeNode *node, vector<int> vals)
    {
        if (!node)
            return;
        vals.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        { // 叶节点
            mVals.push_back(vals);
            return;
        }
        df(node->left, vals);
        df(node->right, vals);
        return;
    }
    vector<vector<int>> mVals;
    vector<string> mResult;
};
// @lc code=end
