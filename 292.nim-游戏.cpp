/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 * 胜利条件：
 * 1.数量充足
 * 2.保证倒数第二手就算全拿也会剩下
 * 易知：第一手拿掉余数，后面按补数拿就行
 * 即，假设总数N 每次可拿k 则需要保证第一手拿 N%(k+1)
 * 剩下的，对手拿i 则自己拿 k+1-i
 * 核心：先拿余数
 */

// @lc code=start
class Solution
{
public:
    bool canWinNim(int n)
    {
        bool result = false;
        if(n<=3)result = true;
        else if(n==4)result = false;
        else if(n>4){
            if(n%4==0)result = false;
            else result = true;
        }
        return result;
    }
};
// @lc code=end
