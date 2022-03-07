/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        vector<double> result;
        // build graph
        map<string, map<string, double>> graph;
        int i = 0;
        for (const auto &eq : equations)
        {
            auto up = eq[0];
            auto down = eq[1];
            graph[up][down] = (double)values[i];
            graph[down][up] = 1.0 / values[i];
            cout << up << "/" << down << values[i] << endl;
            cout << down << "/" << up << 1.0 / values[i] << endl;
            i++;
        }

        // get result
        for (auto que : queries)
        {
            set<string> visited;
            auto val = dfs(que[0], que[1], graph, visited);
            if (val)
                result.push_back(val);
            else
                result.push_back(-1);
        }
        return result;
    }

private:
    double dfs(const string &up, const string &down,
               map<string, map<string, double>> &graph, set<string> visited)
    {
        // 结束条件 找到题目要的分子
        // cout << " up:" << up
        //      << " down:" << down << endl;
        auto subNodes = graph[up];
        if (subNodes.find(down) != subNodes.end())
        {
            // cout << "up:" << up << " down:" << down << ",leaf value is " << graph[up][down] << endl;
            return graph[up][down];
        }
        for (auto node : subNodes)
        {
            if (visited.find(node.first) == visited.end())
            {
                visited.insert(node.first);
                auto leftVals = dfs(node.first, down, graph, visited);
                // cout << "left value is:" << leftVals << endl;
                if (leftVals)
                { //过滤无效值0.0
                    // cout << "process val is "
                    //      << node.second * leftVals << endl;
                    return node.second * leftVals;
                }
            }
        }
        return 0;
    }
};
// @lc code=end
