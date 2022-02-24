#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        vector<int> reversedSum;
        int LenA = a.length();
        int LenB = b.length();
        auto DataA = a.data();
        auto DataB = b.data();
        auto biggerLen = LenA > LenB ? LenA : LenB;
        bool hasAddOne = false;
        for (int i = 0; i < biggerLen; i++)
        {
            //串逆序处理
            int valA = 0;
            int valB = 0;
            if (i >= LenA)
                valA = 0;
            else
                valA = charToInt(DataA[LenA - i - 1]);

            if (i >= LenB)
                valB = 0;
            else
                valB = charToInt(DataB[LenB - i - 1]);
            //按位求值
            int bitSum = valA + valB + (hasAddOne ? 1 : 0);
            int bitVal = bitSum % 2;
            hasAddOne = bitSum >= 2;
            //存储逆序比特值
            reversedSum.push_back(bitVal);
        }
        if (hasAddOne)
            reversedSum.push_back(1);
        string result;
        for (auto it = reversedSum.end() - 1; it >= reversedSum.begin(); it--)
        {
            auto bitVal = to_string(*it);
            result += bitVal;
        }
        return result;
    }
    inline int charToInt(const char &c)
    {
        return c == '1' ? 1 : 0;
    }
};