/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();
        init(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == '0')
                {
                    // 如果是内部 且不属于某一棵树 则去组成树
                    // 如果是边缘 则不处理
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // 如果不属于边树 则设置为X
            }
        }
    }

private:
    void init(int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mTable[i][j] = {-1, -1};
            }
        }
    }
    pair<int, int> find(const pair<int, int> &p)
    {
        if (mTable[p.first][p.second] == pair<int, int>(-1, -1))
        {
            return p;
        }
        else
        {
            return find(pair<int, int>(mTable[p.first][p.second]));
        }
    }
    void merge(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        auto x = find(pair<int, int>(i, j));
        }
    vector<vector<pair<int, int>>> mTable;
};
// @lc code=end
