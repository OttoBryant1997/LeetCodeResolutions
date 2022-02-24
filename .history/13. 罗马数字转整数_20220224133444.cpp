class Solution
{
public:
    int romanToInt(string s)
    {
        size_t strLen = s.length();
        if (strLen == 0)
            return 0;
        int ret = 0;
        auto cStr = s.data();
        for (size_t i = 0; i < strLen; i++)
        {
            auto curValue = getNumByChar(cStr[i]);
            if (i + 1 == strLen)
            {
                ret += curValue;
            }
            else
            {
                auto nextValue = getNumByChar(cStr[i + 1]);
                if (curValue < nextValue)
                {
                    ret += -curValue;
                }
                else
                {
                    ret += curValue;
                }
            }
        }
        return ret;
    }

private:
    int getNumByChar(const char &c)
    {
        int ret = 0;
        switch (c)
        {
        case 'I':
            ret = 1;
            break;
        case 'V':
            ret = 5;
            break;
        case 'X':
            ret = 10;
            break;
        case 'L':
            ret = 50;
            break;
        case 'C':
            ret = 100;
            break;
        case 'D':
            ret = 500;
            break;
        case 'M':
            ret = 1000;
            break;
        }
        return ret;
    }
};