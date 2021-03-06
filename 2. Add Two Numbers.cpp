/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Time Complexity = O(max(M,N))
Space Complexity = O(max(M,N))
M, N are the lengths of the two non-empty linked lists respectively.
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *sumHead, *temp;
        sumHead = new ListNode(0);
        temp = sumHead;
        int sum, carry=0;
        
        while(l1!=NULL || l2!=NULL || carry != 0)
        {
            sum = 0;
            if(l1 != NULL) sum += l1->val;
            if(l2 != NULL) sum += l2->val;
            sum += carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
            if(l1!=NULL)l1 = l1->next;
            if(l2!=NULL)l2 = l2->next;
        }
        return sumHead->next;
    }
};
