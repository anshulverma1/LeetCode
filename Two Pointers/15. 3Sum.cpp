/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

Time Complexity: O(N*N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size()<3) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>vect;
        int left;
        int right;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
               continue;   
            }
            int currentNode=nums[i];
            int currentSum;
            left=i+1;
            right=nums.size()-1;
            while(left<right){
                currentSum=currentNode+nums[left]+nums[right];
                if(currentSum==0){
                    vect.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1])
                        left+=1;
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    left+=1;
                    right-=1;
                }
                else{
                    if(currentSum<0)
                        left+=1;
                    else
                        right-=1;
                }
            }
        }
        return vect;
        
    }
};
