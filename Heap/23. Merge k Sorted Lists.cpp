/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it. 

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Time Complexity: O(N*Log(K)) N = total Nodes, K = Number of Lists.
Space Complexity: O(Log(K)) [Recusion Stack]
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
    
    ListNode* mergeSort(vector<ListNode*> & list, int left, int right)
    {
        if(left == right) return list[left];
        if(left + 1 == right) return mergeTwoLists(list[left], list[right]);
        ListNode* list1 = mergeSort(list, left, left + (right - left)/2);
        ListNode* list2 = mergeSort(list, left + (right - left)/2 + 1, right);
        return mergeTwoLists(list1, list2);
    }
    
    
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) 
    {
        ListNode *prev = new ListNode(-1), *temp = NULL, *th = prev;
        prev->next = h1;
        if(h1==NULL)return h2;
        if(h2==NULL)return h1;
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
        if(h1==NULL && h2!=NULL)prev->next = h2;
        return th->next;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& A) 
    {
        int k = A.size();
        if(k == 0)return NULL;
        if(k == 1)return A[0];
        return mergeSort(A, 0, k-1);
    }
};
