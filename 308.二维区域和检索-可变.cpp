/*
 * @lc app=leetcode.cn id=308 lang=cpp
 *
 * [308] 二维区域和检索 - 可变
 */

// @lc code=start

#include <vector>
using namespace std;
class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        mHorizontalLeft = 0;
        mHorizontalRight = matrix[0].size() - 1;
        mVerticalLeft = 0;
        mVerticalRight = matrix.size() - 1;
        // N*N*2
        auto N = max(matrix.size(), matrix[0].size());
        mTree.resize(N * N * 2);
        buildTree(mHorizontalLeft, mHorizontalRight, mVerticalLeft, mVerticalRight, matrix);
    }

    void update(int row, int col, int val)
    {
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return 0;
    }

private:
    vector<int> mTree;
    int mHorizontalLeft = 0;
    int mHorizontalRight = 0;
    int mVerticalLeft = 0;
    int mVerticalRight = 0;

private:
    void buildTree(int horL, int horR, int verL, int verR, vector<vector<int>> &data, int treeIndex = 0)
    {
        auto w = horR - horL; //宽度
        auto h = verR - verL; //高度
        if (w < 0 || h < 0)
            return;
        if (w * h == 1)
            mTree[treeIndex] = data[verL][horL];
        auto horMid = horL + (w >> 1); //水平中心
        auto verMid = verL + (h >> 1); //垂直中心

        //以下是理想结构
        //依次构建四个子树
        //左上子树
        buildTree(horL, horR, verL, verR, data, treeIndex * 4 + 1);
        //右上子树
        buildTree(horL, horR, verL, verR, data, treeIndex * 4 + 2);
        //左下子树
        buildTree(horL, horR, verL, verR, data, treeIndex * 4 + 3);
        //右下子树
        buildTree(horL, horR, verL, verR, data, treeIndex * 4 + 4);
        mTree[treeIndex] = mTree[treeIndex * 4 + 1] + mTree[treeIndex * 4 + 2] + mTree[treeIndex * 4 + 3] + mTree[treeIndex * 4 + 4];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
