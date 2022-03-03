/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        //数据处理
        vector<string> result;
        m_hour.resize(5);
        m_min.resize(7);
        for (int i = 0; i < 12; i++)
        {
            auto bitNum = getHourBitNum(i);
            m_hour[bitNum].push_back(to_string(i));
        }
        for (int i = 0; i < 60; i++)
        {
            auto bitNum = getMinBitNum(i);
            string minVal = "";
            if (i < 10)
            {
                minVal = "0" + to_string(i);
            }
            else
            {
                minVal = to_string(i);
            }
            m_min[bitNum].push_back(minVal);
        }

        //计算
        for (int i = 0; i <= 4 && i <= turnedOn; i++)
        {
            cout << "i:" << i << "turnedOn-i:" << turnedOn - i << endl;
            // 小时使用位数 i 分钟使用个数
            if (turnedOn - i >= 0 && turnedOn - i < m_min.size())
            {
                if (m_hour[i].size() > 0 && m_min[turnedOn - i].size() > 0)
                {
                    for (auto h : m_hour[i])
                    {
                        for (auto min : m_min[turnedOn - i])
                        {
                            string time;
                            time = h + ":" + min;
                            result.push_back(time);
                        }
                    }
                }
            }
        }
        return result;
    }

private:
    vector<vector<string>> m_hour;
    vector<vector<string>> m_min;
    int getHourBitNum(const int n)
    {
        int bit = 1;
        int result = 0;
        for (int i = 0; i < 4; i++)
        {
            if (n & bit)
            {
                result++;
            }
            bit <<= 1;
        }
        return result;
    }
    int getMinBitNum(const int n)
    {
        int bit = 1;
        int result = 0;
        for (int i = 0; i < 6; i++)
        {
            if (n & bit)
            {
                result++;
            }
            bit <<= 1;
        }
        return result;
    }
};
// @lc code=end
