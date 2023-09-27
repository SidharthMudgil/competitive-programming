// USER: SIDHARTH MUDGIL
// DATE: Wednesday 18, Jan 2023
// TASK: 206. Reverse Linked List

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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    while (head)
    {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main()
{
    return 0;
}