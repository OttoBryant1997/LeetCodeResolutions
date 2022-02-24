#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        bool isValid = false;
        stack<string> cached;
        int size = s.length();
        if (size == 0)
            return false;
        for (int i = 0; i < size; i++)
        {
            auto ss = s.substr(i, 1);
            if (isLeftPart(ss))
            {
                cached.push(ss);
            }
            else if (isRightPart(ss) && cached.size() > 0)
            {
                auto needLeftPart = cached.top();
                if (!isLeftPart(needLeftPart))
                    break;
                else
                {
                    if (isPair(needLeftPart, ss))
                    {
                        cached.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        isValid = cached.size() == 0;
        return isValid;
    }

private:
    inline bool isPair(const string &left, const string &right)
    {
        return (left == "(" && right == ")") || (left == "{" && right == "}") || (left == "[" && right == "]");
    }
    inline bool isRightPart(const string &c)
    {
        return c == ")" || c == "}" || c == "]";
    }
    inline bool isLeftPart(const string &c)
    {
        return c == "(" || c == "{" || c == "[";
    }
};