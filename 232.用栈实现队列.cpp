/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <deque>
using namespace std;
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        mDeque.push_back(x);
    }

    int pop()
    {
        auto val = mDeque.front();
        mDeque.pop_front();
        return val;
    }

    int peek()
    {
        return mDeque.front();
    }

    bool empty()
    {
        return mDeque.empty();
    }

protected:
    deque<int> mDeque;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
