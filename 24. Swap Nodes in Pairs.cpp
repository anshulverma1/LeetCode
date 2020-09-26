/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Time Complexity: O(N)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode *tHead = new ListNode(-1);
        tHead->next = head;
        ListNode *prev = tHead;
        while(prev!=NULL && prev->next!=NULL && prev->next->next!=NULL)
        {
            ListNode *t1 = prev->next;
            ListNode *t2 = t1->next->next;
            prev->next = t1->next;
            prev->next->next = t1;
            t1->next = t2;
            prev = t1;
        }
        head = tHead->next;
        delete(tHead);
        return head;
        
    }
};
