/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <vector>

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        mStack.push_back(val);
    }

    void pop()
    {
        mStack.pop_back();
    }

    int top()
    {
        if (mStack.size() > 0)
            return mStack[mStack.size() - 1];
        else
            return -1;
    }

    int getMin()
    {
        int curMin = mStack[0];

        for (auto &i : mStack)
        {
            if (curMin > i)
                curMin = i;
        }
        return curMin;
    }

private:
    vector<int> mStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
