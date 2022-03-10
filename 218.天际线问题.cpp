/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */

// @lc code=start
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> result;
        multiset<pair<int, int>> orderedPoint;
        for (int i = 0; i < buildings.size(); i++)
        {
            orderedPoint.insert({buildings[i][0], -buildings[i][2]}); // (left,-height)
            orderedPoint.insert({buildings[i][1], buildings[i][2]});  // (right,height)
            // cout << "left:" << buildings[i][0] << ", right:" << buildings[i][1] << ",height:" << buildings[i][2] << endl;
        }
        //存储当前所有的高度 最大高度是 heights.rbegin();
        multiset<int> heights;
        int lastHigest = 0; //上一个最高值
        for (auto &pair : orderedPoint)
        {
            // cout << "x:" << pair.first << " y:" << pair.second << endl;
            //建筑的左右点都可能引起高度
            if (pair.second > 0)
            { // right,height
                //直接调用erase(val)会移除所有值
                heights.erase(heights.find(pair.second));
            }
            else
            { // left,-height
                heights.insert(-pair.second);
            }

            if (heights.size())
            {
                auto curHighest = *heights.rbegin(); //当前最高值
                // 最大高度变化时可以插入新的 l,h
                // cout << "lastHigest:" << lastHigest << ",curHighest:" << curHighest << endl;
                if (lastHigest != curHighest)
                {
                    result.push_back({pair.first, *heights.rbegin()});
                    lastHigest = curHighest;
                }
            }
            else
            { //最后情况 遍历完了
                result.push_back({pair.first, 0});
            }
        }
        return result;
    }
};
// @lc code=end
