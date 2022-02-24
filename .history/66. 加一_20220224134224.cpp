#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> tmp;
        auto size = digits.size();
        bool needAddOne = true;
        // 2399
        // 999
        for (int i = size - 1; i >= 0; i--)
        {
            if (digits[i] == 9 && needAddOne)
            {
                tmp.push_back(0);
            }
            else
            {
                if (needAddOne)
                {
                    tmp.push_back(digits[i] + 1);
                    needAddOne = false;
                }
                else
                {
                    tmp.push_back(digits[i]);
                }
            }
        }
        if (needAddOne)
            tmp.push_back(1);
        //翻转
        vector<int> ret;
        for (auto it = tmp.end() - 1; it >= tmp.begin(); it--)
        {
            ret.push_back(*it);
        }
        return ret;
    }
};