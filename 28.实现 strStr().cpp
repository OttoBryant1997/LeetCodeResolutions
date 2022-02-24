#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // auto haystackData = haystack.data();
        // auto needleData = needle.data();
        // auto haystackLen = haystack.length();
        // auto needleLen = needle.length();
        // if (needleLen == 0)
        //     return 0;
        // if (haystackLen == 0 || haystackLen < needleLen)
        //     return -1;
        // for (int i = 0; i < haystackLen; i++)
        // {
        //     if (i + needleLen <= haystackLen)
        //     {
        //         if (haystackData[i] == needleData[0])
        //         {
        //             if (haystack.substr(i, needleLen) == needle)
        //                 return i;
        //         }
        //     }
        // }
        // return -1;
        auto position = haystack.find(needle);
        if (position != haystack.npos)
            return position;
        else
            return -1;
    }
};