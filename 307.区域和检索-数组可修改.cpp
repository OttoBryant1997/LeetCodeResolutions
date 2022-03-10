/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
#include <vector>
using namespace std;
class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        mLeft = 0;
        mRight = nums.size() - 1;
        mTree.resize(nums.size() * 4);
        buildTree(0, mRight, nums);
    }

    void update(int index, int val)
    {
        update(mLeft, mRight, index, val);
    }

    int sumRange(int left, int right)
    {
        return sumRange(mLeft, mRight, left, right);
    }

private:
    vector<int> mTree;
    int mLeft = 0;
    int mRight = 0;
    void buildTree(int dataLeftIndex, int dataRightIndex, vector<int> &data, int treeIndex = 0)
    {
        if (dataLeftIndex == dataRightIndex)
        {
            mTree[treeIndex] = data[dataLeftIndex];
            return;
        }
        auto mid = dataLeftIndex + ((dataRightIndex - dataLeftIndex) >> 1);
        buildTree(dataLeftIndex, mid, data, treeIndex * 2 + 1);
        buildTree(mid + 1, dataRightIndex, data, treeIndex * 2 + 2);
        mTree[treeIndex] = mTree[treeIndex * 2 + 1] + mTree[treeIndex * 2 + 2];
    }
    void update(int dataLeftIndex, int dataRightIndex, int targetIndex, int targetVal, int treeIndex = 0)
    {

        if (dataLeftIndex == dataRightIndex && dataRightIndex == targetIndex)
        {
            mTree[treeIndex] = targetVal;
            return;
        }
        auto mid = dataLeftIndex + ((dataRightIndex - dataLeftIndex) >> 1);
        // cout << "update,dataRightIndex:"
        //      << dataRightIndex << " dataLeftIndex:" << dataLeftIndex << " mid:" << mid
        //      << " targetIndex:" << targetIndex << endl;
        if (targetIndex <= mid)
            update(dataLeftIndex, mid, targetIndex, targetVal, treeIndex * 2 + 1);
        else
            update(mid + 1, dataRightIndex, targetIndex, targetVal, treeIndex * 2 + 2);
        mTree[treeIndex] = mTree[treeIndex * 2 + 1] + mTree[treeIndex * 2 + 2];
    }
    int sumRange(int dataLeftIndex, int dataRightIndex, int targetLeftIndex, int targetRightIndex, int treeIndex = 0)
    {
        // cout << "sumRange" << endl;
        if (dataLeftIndex == targetLeftIndex && dataRightIndex == targetRightIndex)
        {
            return mTree[treeIndex];
        }
        auto mid = dataLeftIndex + ((dataRightIndex - dataLeftIndex) >> 1);
        if (targetRightIndex <= mid)
        {
            return sumRange(dataLeftIndex, mid, targetLeftIndex, targetRightIndex, treeIndex * 2 + 1);
        }
        else if (mid < targetLeftIndex)
        {
            return sumRange(mid + 1, dataRightIndex, targetLeftIndex, targetRightIndex, treeIndex * 2 + 2);
        }
        else
        {
            return sumRange(dataLeftIndex, mid, targetLeftIndex, mid, treeIndex * 2 + 1) + sumRange(mid + 1, dataRightIndex, mid + 1, targetRightIndex, treeIndex * 2 + 2);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
