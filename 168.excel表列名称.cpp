/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 * 商余法
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
string intToString(int value)
{
    string str;
    switch (value)
    {
    case 1:
        str = "A";
        break;
    case 2:
        str = "B";
        break;
    case 3:
        str = "C";
        break;
    case 4:
        str = "D";
        break;
    case 5:
        str = "E";
        break;
    case 6:
        str = "F";
        break;
    case 7:
        str = "G";
        break;
    case 8:
        str = "H";
        break;
    case 9:
        str = "I";
        break;
    case 10:
        str = "J";
        break;
    case 11:
        str = "K";
        break;
    case 12:
        str = "L";
        break;
    case 13:
        str = "M";
        break;
    case 14:
        str = "N";
        break;
    case 15:
        str = "O";
        break;
    case 16:
        str = "P";
        break;
    case 17:
        str = "Q";
        break;
    case 18:
        str = "R";
        break;
    case 19:
        str = "S";
        break;
    case 20:
        str = "T";
        break;
    case 21:
        str = "U";
        break;
    case 22:
        str = "V";
        break;
    case 23:
        str = "W";
        break;
    case 24:
        str = "X";
        break;
    case 25:
        str = "Y";
        break;
    case 26:
        str = "Z";
        break;
    }
    return str;
}
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        vector<int> vals;
        string result;
        int divVal = 0;
        do
        {
            divVal = columnNumber / 26;
            int redunt = columnNumber - divVal * 26;
            if (redunt == 0)
            {
                columnNumber = columnNumber / 26 - 1;
                divVal -= 1;
                redunt += 26;
            }
            else
            {
                columnNumber /= 26;
            }
            vals.push_back(redunt);

        } while (divVal > 0);
        vals.push_back(divVal);
        for (auto it = vals.end() - 1; it >= vals.begin(); it--)
        {
            result += intToString(*it);
        }
        return result;
    }
};
// @lc code=end
