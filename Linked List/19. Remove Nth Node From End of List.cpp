/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note: Given n will always be valid.
Follow up: Could you do this in one pass?

Time Complexity: O(N) [One Pass]
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *dummy = new ListNode(-1), *toEnd = head, *prev = dummy;
        prev->next = head;
        
        for(int i = 0; i < n; i++) toEnd = toEnd->next;
        
        while(toEnd != nullptr)
        {
            prev = prev->next;
            toEnd = toEnd->next;
        }
        
        if(prev == dummy)
        {
            delete(dummy);
            return head->next;
        }
        else
        {
            delete(dummy);
            prev->next = prev->next->next;
        }
        
        return head;        
    }
};
