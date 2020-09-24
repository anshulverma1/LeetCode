/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

Time Complexity: O(M + N)
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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) 
    {
        ListNode *prev = new ListNode(-1), *temp = NULL, *th = prev;
        prev->next = h1;
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        while(h1!=NULL && h2!=NULL)
        {
            if(h1->val >= h2->val)
            {
                temp = h2->next;
                prev->next = h2;
                h2->next = h1;
                h2 = temp;
                prev = prev->next;
            }
            else
            {
                h1 = h1->next;
                prev = prev->next;
            }
        }
        if(h1==NULL && h2!=NULL) prev->next = h2;
        return th->next;        
    }
};
