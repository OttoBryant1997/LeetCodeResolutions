
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 && !list2)
            return nullptr;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        vector<int> values;
        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                values.push_back(p1->val);
                p1 = p1->next;
            }
            else
            {
                values.push_back(p2->val);
                p2 = p2->next;
            }
        }
        ListNode *leftedList = p1 ? p1 : p2;
        while (leftedList)
        {
            values.push_back(leftedList->val);
            leftedList = leftedList->next;
        }
        ListNode *resultList = nullptr;
        ListNode *resultListTail = nullptr;
        for (auto val : values)
        {
            cout << "val:" << val << endl;
            auto newNode = new ListNode(val);
            if (!resultList)
            {
                resultList = newNode;
            }
            else
            {
                resultListTail->next = newNode;
            }
            resultListTail = newNode;
        }
        return resultList;
    }
};