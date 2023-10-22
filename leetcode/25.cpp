/*

25. Reverse Nodes in k-Group
Difficulty: Hard
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

*/

#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to reverse ListNode of size k starting from given node
pair<ListNode*,ListNode*> reverse(ListNode *start, int k) {
    if(start == NULL) return {NULL, NULL};
    int cnt = 0;
    // 'next' is the node which points to (k+1)th node (next node to 'end' node)
    ListNode *next = start, *end = NULL;
    while(next && cnt<k) {
        end = next;
        next = next->next;
        cnt++;
    }
    // Return if length not equal to k
    if(cnt < k) return {start, end};

    // Reverse nodes between 'start' and 'end' node including them
    ListNode *left = NULL;
    ListNode *it = start;
    while(it != next) {
        ListNode *temp = it->next;
        it->next = left;
        left = it;
        it = temp;
    }

    // Point the new end of the selected nodes to next node in the overall list
    start->next = next;
    return {end, start};
}

// Function to reverse nodes in k groups
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *root = new ListNode(-1);
    ListNode *it = root;
    it->next = head;
    while(it) {
        pair<ListNode*,ListNode*> rev = reverse(it->next, k);
        
        // Point the current node to start of reversed nodes
        it->next = rev.first;
        it = rev.second;
    }
    head = root->next;
    delete(root);
    return head;
}

// Driver Function
int main() {
	ListNode *root = new ListNode(-1);
	cout<<"Enter Size of List: ";
	int n;
	cin>>n;
	cout<<"Enter Numbers: ";
	ListNode *it = root;
	while(n--) {
		int value;
		cin>>value;
		it->next = new ListNode(value);
		it = it->next;
	}
	int k;
	cout<<"Enter K: ";
	cin>>k;

	ListNode *head = root->next;
	delete(root);
	head = reverseKGroup(head, k);

	cout<<"Reversed K List: ";
	it = head;
	while(it) {
		cout<<it->val<<" ";
		it=it->next;
	}
	cout<<"\n";
	return 0;
}