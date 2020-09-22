/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

Time Complexity: O(N^3)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) 
    {
        vector<vector<int> > res;
        if(A.size() < 4)return res;
        sort(A.begin(), A.end());
        int n = A.size();
        for(int i = 0; i < n-3; i++)
        {
            if(i > 0 && A[i] == A[i-1])continue;
            if(A[i]+A[i+1]+A[i+2]+A[i+3]>target) break;
            if(A[i]+A[n-3]+A[n-2]+A[n-1]<target) continue;
            for(int j = i+1; j < n-2; j++)
            {
                if(j > i+1 && A[j] == A[j-1])continue;
                if(A[i]+A[j]+A[j+1]+A[j+2]>target) break;
                if(A[i]+A[j]+A[n-2]+A[n-1]<target) continue;
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    int sum = A[i] + A[j] + A[left] + A[right];
                    if(sum < target)left++;
                    else if(sum > target)right--;
                    else
                    {
                        res.push_back({A[i],A[j],A[left],A[right]});
                        while(left < right && A[left] == A[left+1])left++;
                        while(left < right && A[right] == A[right-1])right--;
                        left++,right--;
                    }
                }
            }
        }
        return res;
        
    }
};
