#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        auto sl = s.length();
        auto sData = s.data();
        int len = 0;
        for (int i = sl - 1; i >= 0; i--)
        {

            if (sData[i] != ' ')
            {
                for (int j = i; j >= 0; j--)
                {
                    if (sData[j] != ' ')
                        len++;
                    else
                        break;
                }
                return len;
            }
        }
        return len;
    }
};