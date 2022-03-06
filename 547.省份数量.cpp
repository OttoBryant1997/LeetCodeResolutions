/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 *
 * 并查集的两个必写函数 find 和 merge
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> arr(isConnected.size(), -1);

        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = i + 1; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    connect(i, j, arr);
                }
            }
        }
        int result = 0;
        for (auto val : arr)
        {
            if (val == -1)
            {
                result++;
            }
        }
        return result;
    }

private:
    int find(int i, vector<int> &arr)
    {
        if (arr[i] == -1)
            return i;
        else
            return find(arr[i], arr);
    }
    void connect(int i, int j, vector<int> &arr)
    {
        auto leaderI = find(i, arr);
        auto leaderJ = find(j, arr);
        if (leaderI == leaderJ)
        {
            return;
        }
        arr[leaderI] = leaderJ;
    }
};
// @lc code=end
