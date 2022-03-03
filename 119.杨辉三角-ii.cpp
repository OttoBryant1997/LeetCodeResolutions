/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> triangle;
        triangle.resize(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    triangle[i].push_back(1);
                }
                else
                {
                    int val = triangle[i - 1][j - 1] + triangle[i - 1][j];
                    triangle[i].push_back(val);
                }
            }
        }
        return triangle[rowIndex];
    }
};
// @lc code=end
