/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <vector>
using namespace std;
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        mVec.push_back(x);
    }

    int pop()
    {
        auto val = top();
        mVec.pop_back();
        return val;
    }

    int top()
    {
        return mVec[mVec.size() - 1];
    }

    bool empty()
    {
        return mVec.size() == 0;
    }

protected:
    vector<int> mVec;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
