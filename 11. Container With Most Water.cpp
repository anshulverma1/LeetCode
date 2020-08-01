/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int mx = 0,l = 0,r = h.size()-1;
        while(l < r)
        {
            mx = max(mx, min(h[l], h[r])*(r-l));
            if(h[l] < h[r])l++;
            else r--;
        }
        return mx;
           
    }
};
