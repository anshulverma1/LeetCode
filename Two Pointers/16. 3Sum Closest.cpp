/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
Constraints:
3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

Time Complexity: O(N*N)
Space Complexity: O(1)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) 
    {
        int diff = INT_MAX, closestSum  = 0;        
        sort(A.begin(), A.end());        
        for(int i = 0; i < A.size()-2; i++)
        {
            int left = i+1, right = A.size()-1;
            while(left < right)
            {
                if(diff > abs( A[i] + A[left] + A[right] - target))
                {
                    closestSum = A[i] + A[left] + A[right];
                    diff = abs(A[i] + A[left] + A[right] - target);
                }
                if(diff == 0) return target;
                else if(A[i] + A[left] + A[right] > target) right--;
                else left++;
            }
        }
        return closestSum;
    }
};
