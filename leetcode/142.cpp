// USER: SIDHARTH MUDGIL
// DATE: Thursday 19, Jan 2023
// TASK: 142. Linked List Cycle II

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ListNode *detectCycle(ListNode *head)
// {
//     vector<ListNode *> visited;
//     visited.push_back(head);

//     while (head && head->next)
//     {
//         for (int i = 0; i < visited.size(); i++)
//         {
//             if (visited[i] == head->next)
//                 return head->next;
//         }
//         visited.push_back(head->next);
//         head = head->next;
//     }

//     return nullptr;
// }

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            while (slow != head)
            {
                slow = slow->next;
                head = head->next;
            }
            return head;
        }
    }

    return nullptr;
}

int main()
{
    return 0;
}