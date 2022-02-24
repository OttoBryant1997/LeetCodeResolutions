#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        //输入处理
        map<int, vector<int>> mapValueIdx;
        for (int i = 0; i < nums.size(); i++)
        {
            auto num = nums.at(i);
            if (mapValueIdx.find(num) == mapValueIdx.end())
            {
                mapValueIdx.insert({num, vector<int>{i}});
            }
            else
            {
                auto vecIndex = (*mapValueIdx.find(num)).second;
                vecIndex.push_back(i);
                mapValueIdx[num] = vecIndex;
            }
        }
        //计算
        for (int i = 0; i < nums.size(); i++)
        {
            auto num = nums.at(i);
            auto lefted = target - num;
            if (num == lefted)
            {
                auto vecIndex = (*mapValueIdx.find(num)).second;
                if (vecIndex.size() >= 2)
                {
                    auto leftedIndex = vecIndex[1];
                    ret.push_back(i);
                    ret.push_back(leftedIndex);
                    break;
                }
            }
            else
            {
                auto iter = mapValueIdx.find(lefted);
                if (iter != mapValueIdx.end())
                {
                    auto leftedIndex = (*iter).second.at(0);
                    ret.push_back(i);
                    ret.push_back(leftedIndex);
                    break;
                }
            }
        }
        return ret;
    }
};