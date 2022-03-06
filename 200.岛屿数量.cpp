/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                result += dfs(i, j, grid);
            }
        }
        return result;
    }

private:
    inline int dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        if (grid[i][j] == '0')
            return 0;
        grid[i][j] = '0';
        //上下左右
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
        return 1;
    }
};
// @lc code=end
