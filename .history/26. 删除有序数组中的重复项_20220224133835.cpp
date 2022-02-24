#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> tmp;
        auto it = nums.begin();

        while (it != nums.end())
        {
            if (tmp.find(*it) == tmp.end())
            {
                tmp.insert(*it);
                it++;
            }
            else
            {
                it = nums.erase(it);
            }
        }
        return nums.size();
    }
};