#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (auto it = nums.begin(); it != nums.end();)
        {
            if (*it == val)
            {
                auto nextIt = nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
};