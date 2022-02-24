/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 * O(M+N)
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        if (m == 0)
        {
            for (int i = 0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
            return;
        }
        auto pVals = new int[m + n];
        int idxNums1 = 0;
        int idxNums2 = 0;
        int smallerValue = 0;
        // nums1 = [1, 2, 3, 4, 5, 6, 7, 8, 9 , 0,0,0]
        // nums2 = [2, 5, 6]
        bool isNums1Finish = false;
        bool isNums2Finish = false;
        for (int i = 0; i < m + n; i++)
        {
            if (!isNums1Finish && !isNums2Finish)
            {
                if (nums1[idxNums1] < nums2[idxNums2])
                {
                    smallerValue = nums1[idxNums1];
                    idxNums1++;
                    isNums1Finish = idxNums1 == m;
                }
                else
                {
                    smallerValue = nums2[idxNums2];
                    idxNums2++;
                    isNums2Finish = idxNums2 == n;
                }
            }
            else
            {
                if (isNums1Finish)
                {
                    smallerValue = nums2[idxNums2];
                    idxNums2++;
                }
                else
                {
                    smallerValue = nums1[idxNums1];
                    idxNums1++;
                }
            }
            pVals[i] = smallerValue;
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = pVals[i];
        }
        delete[] pVals;
    }
};
// @lc code=end
