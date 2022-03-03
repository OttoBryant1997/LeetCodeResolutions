/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int countSegments(string s)
    {
        int result = 0;
        bool isLastCharValid = false; //上一个是不是有效字符
        int size = s.length();
        string word;
        vector<string> words;
        for (int i = 0; i < size; i++)
        {
            auto c = s.substr(i, 1);
            if (c == " ")
            {
                if (isLastCharValid && word.length() > 0)
                {
                    words.push_back(word);
                }
                else
                {
                }
                isLastCharValid = false;
            }
            else
            {
                word += c;
                isLastCharValid = true;
            }
        }
        if (isLastCharValid)
            result = words.size() + 1;
        else
            result = words.size();
        return result;
    }
};
// @lc code=end
