/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        
        vector <int> res;
        unordered_map <int,int> m;
        for (int i = 0; i < A.size(); i++) 
        { 
             if(i==0) m.insert({A[i],i});
            else
            {
                int x = target-A[i];
                auto it = m.find(x);
                if(it != m.end())
                {
                    res.push_back(it->second);
                    res.push_back(i);
                    break;                   
                }
                else m.insert({A[i],i});
            }
        } 
        return res;
        
        
    }
};
