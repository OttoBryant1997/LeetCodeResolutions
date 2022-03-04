/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        vector<int> result;
        int maybeRoot = sqrt(area);
        for (int i = maybeRoot; i > 0; i--)
        {
            if (area % i == 0)
            {
                result.push_back(i);
                result.push_back(area / i);
                break;
            }
        }
        if (result.size() > 0)
        {
            if (result[0] < result[1])
            {
                int tmp = result[0];
                result[0] = result[1];
                result[1] = tmp;
            }
        }
        return result;
    }
};
// @lc code=end
