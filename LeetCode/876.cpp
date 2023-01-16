// USER: SIDHARTH MUDGIL
// DATE: Monday 16, Jan 2023
// TASK: 876. Middle of the Linked List

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        count = count / 2 + 1;

        while (--count)
        {
            head = head->next;
        }

        return head;
    }
};