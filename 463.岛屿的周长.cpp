/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * 1.四个方向的判定
 * 2.边界或者交界加1
 * 3.避免重复计数 仅对岛屿计数
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        mGrid = grid;
        mRow = grid.size();
        mColumn = grid[0].size();
        int result = 0;
        for (int i = 0; i < mRow; i++)
        {
            for (int j = 0; j < mColumn; j++)
            {
                if (grid[i][j] == 1)
                {
                    // 上
                    if (isEdge(i, j, i - 1, j))
                        result++;
                    // 下
                    if (isEdge(i, j, i + 1, j))
                        result++;
                    // 左
                    if (isEdge(i, j, i, j - 1))
                        result++;
                    // 右
                    if (isEdge(i, j, i, j + 1))
                        result++;
                }
            }
        }
        return result;
    }

private:
    //判断两个块是不是有有效边界
    bool isEdge(int thisI, int thisJ, int otherI, int otherJ)
    { //保证thisI,thisJ是岛屿
        if (otherI < 0 || otherJ < 0 || otherI >= mRow || otherJ >= mColumn)
            return true;
        return mGrid[otherI][otherJ] == 0;
    }
    vector<vector<int>> mGrid;
    int mColumn = 0;
    int mRow = 0;
};
// @lc code=end
