/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 * 优先队列
 */

// @lc code=start
#include <queue>
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < score.size(); i++)
            q.push({score[i], i});
        int i = 0;
        vector<string> a(size(q));
        while (!q.empty())
        {
            a[q.top().second] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal"
                                                    : i == 2   ? "Bronze Medal"
                                                               : to_string(i + 1);
            i++;
            q.pop();
        }
        return a;
    }
};
// @lc code=end
