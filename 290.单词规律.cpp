/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include <vector>
#include <string>
#include <regex>
#include <map>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        auto pL = pattern.length();
        vector<string> strList;
        map<string, string> cToStr;
        map<string, string> StrToC;
        Stringsplit(s, " ", strList);
        bool result = true;
        if (strList.size() != pattern.length())
        {
            return false;
        }
        for (int i = 0; i < pL; i++)
        {
            auto pC = pattern.substr(i, 1);
            auto strI = strList[i];
            bool status1 = cToStr.find(pC) == cToStr.end();
            bool status2 = StrToC.find(strI) == StrToC.end();
            if (status1 && status2)
            {
                cToStr.insert({pC, strI});
                StrToC.insert({strI, pC});
            }
            else
            {
                if (status1)
                { //无 char to str的映射
                    if (StrToC[strI] != pC)
                    {
                        result = false;
                        break;
                    }
                }
                else
                {
                    if (cToStr[pC] != strI)
                    {
                        result = false;
                        break;
                    }
                }
            }
        }
        return result;
    }

private:
    void Stringsplit(const string &str, const string &split, vector<string> &res)
    {
        // std::regex ws_re("\\s+"); // 正则表达式,匹配空格
        std::regex reg(split); // 匹配split
        std::sregex_token_iterator pos(str.begin(), str.end(), reg, -1);
        decltype(pos) end; // 自动推导类型
        for (; pos != end; ++pos)
        {
            res.push_back(pos->str());
        }
    }
};
// @lc code=end
