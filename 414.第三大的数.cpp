/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int result = 0;
        sort(nums.begin(), nums.end());
        set<int> s;
        vector<int> norepet;
        for (auto i : nums)
        {
            if (s.find(i) == s.end())
            {
                norepet.push_back(i);
                s.insert(i);
            }
        }
        cout << "norepet.size:" << norepet.size() << endl;
        if (norepet.size() < 3)
        {
            cout << "if";
            result = norepet[norepet.size() - 1];
        }
        else
        {
            cout << "else";
            result = norepet[norepet.size() - 1 - 2];
        }
        return result;
    }
};
// @lc code=end
