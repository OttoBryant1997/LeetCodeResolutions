class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        //输入处理
        vector<int> Digits;
        while (x >= 10)
        {
            Digits.push_back(x % 10);
            x /= 10;
        }
        Digits.push_back(x % 10);
        //计算
        bool ret = true;
        auto len = Digits.size();
        auto it_times = 0;
        if (len % 2 == 0)
        {
            it_times = len / 2;
        }
        else
        {
            it_times = len / 2 + 1;
        }
        for (int i = 0; i < it_times; i++)
        {
            if (Digits.at(i) != Digits.at(len - 1 - i))
            {
                ret = false;
                break;
            }
        }
        return ret;
    }
};