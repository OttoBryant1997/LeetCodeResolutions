/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int sizeN1 = num1.length();
        int sizeN2 = num2.length();
        string result = "";
        int addOn = 0;
        int biggerLen = sizeN1 > sizeN2 ? sizeN1 : sizeN2;
        map<int, string> mpIntToString = {{0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}};
        map<string, int> mpStringToInt = {{"0", 0}, {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}};
        for (int i = 0; i < biggerLen; i++)
        {
            int val1 = 0;
            int val2 = 0;
            if (i < sizeN1)
            {
                val1 = mpStringToInt[num1.substr(sizeN1 - i - 1, 1)];
            }
            if (i < sizeN2)
            {
                val2 = mpStringToInt[num2.substr(sizeN2 - i - 1, 1)];
            }
            int sum = val1 + val2 + addOn;
            addOn = sum / 10;
            result = mpIntToString[sum % 10] + result;
        }
        if (addOn > 0)
        {
            result = mpIntToString[addOn] + result;
        }
        return result;
    }

private:
};
// @lc code=end
