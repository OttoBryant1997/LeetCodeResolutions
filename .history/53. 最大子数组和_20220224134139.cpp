#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0;
        int maxAns = nums[0];
        for (const auto &val : nums)
        {
            pre = max(pre + val, val);
            maxAns = max(pre, maxAns);
        }
        return maxAns;
    }
};