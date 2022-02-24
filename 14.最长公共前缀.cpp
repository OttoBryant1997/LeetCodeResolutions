class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];
        string ret;
        int minLength = INT_MAX;
        for (auto &str : strs)
        {
            auto strLen = str.length();
            if (minLength > strLen)
                minLength = strLen;
        }
        if (minLength == 0)
            return "";
        vector<string> chars;
        bool isContinue = true;
        for (int i = 0; i < minLength && isContinue; i++)
        {
            chars.push_back(strs[0].substr(i, 1));
            for (auto &str : strs)
            {
                if (str.substr(i, 1) != chars.at(i))
                {
                    chars.pop_back();
                    isContinue = false;
                    break;
                }
            }
        }
        for (auto &sameChar : chars)
        {
            ret += sameChar;
        }
        return ret;
    }
};