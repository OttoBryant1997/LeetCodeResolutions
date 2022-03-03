/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        auto hexLen = sizeof(int) * 2;
        map<int, string> mapIntHex = {{0, "0"}, {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "a"}, {11, "b"}, {12, "c"}, {13, "d"}, {14, "e"}, {15, "f"}};
        string result = "";
        vector<string> tmp;
        for (int i = 0; i < hexLen; i++)
        {
            auto val = num & 0xf;
            tmp.push_back(mapIntHex[val]);
            num >>= 4;
            // cout << mapIntHex[val] << endl;
        }
        bool start = false;
        int size = tmp.size();
        for (int i = 0; i < size; i++)
        {
            if (tmp[size - i - 1] == "0" && !start)
                continue;
            result += tmp[size - i - 1];
            start = true;
        }
        return result;
    }
};
// @lc code=end
