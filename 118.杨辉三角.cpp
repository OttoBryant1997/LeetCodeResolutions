// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem118.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.resize(numRows);
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    result[i].push_back(1);
                }
                else
                {
                    int val = result[i - 1][j - 1] + result[i - 1][j];
                    result[i].push_back(val);
                }
            }
        }
        return result;
    }
};
// @lc code=end
